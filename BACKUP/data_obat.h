// data_obat.h

#ifndef DATA_OBAT_H
#define DATA_OBAT_H

#include <string>
using std::string;

// Data obat dalam bentuk array global (hanya untuk inisialisasi awal)
const int JUMLAH_OBAT = 200;

const string NAMA_OBAT[JUMLAH_OBAT] = {
    // 1-20 (Obat Bebas)
    "Paracetamol 500 mg",
    "Ibuprofen",
    "Antasida(promagh)",
    "Cetrizine 10 mg",
    "Loperamide",
    "Bodrex flu dan batuk",
    "Paramex",
    "Amoxicillin 500 mg",
    "Ciprofloxacin 500 mg",
    "Azithromycin 500 mg",
    "Omeprazole 20 mg",
    "Ranitidine 150 mg",
    "Vitamin C 500 mg",
    "Vitamin D3 1000 IU",
    "Zinc 20 mg",
    "Betadine Solusi 15 ml",
    "Insto reguler 15 ml",
    "Kool Fever Dewasa",
    "Kool Fever Anak",
    "Kool Fever Bayi",

    // 21-40 (Obat Bebas Terbatas)
    "Pseudoephedrine HCl 30 mg",
    "Dextromethorphan 15 mg",
    "Diphenhydramine 25 mg",
    "Phenylephrine 10 mg",
    "Codeine Phosphate 10 mg",
    "Tramadol HCl 50 mg",
    "Loratadine 10 mg",
    "Chlorpheniramine Maleate 4 mg",
    "Salbutamol 2 mg",
    "Theophylline 100 mg",
    "Methylphenidate 10 mg",
    "Phentermine 15 mg",
    "Alprazolam 0.25 mg",
    "Diazepam 5 mg",
    "Lorazepam 1 mg",
    "Midazolam 5 mg",
    "Ranitidine HCl 150 mg",
    "Famotidine 20 mg",
    "Rabeprazole 20 mg",
    "Esomeprazole 40 mg",

    // 41-60 (Obat Keras)
    "Metformin 500 mg",
    "Insulin Regular",
    "Insulin Lispro",
    "Atorvastatin 20 mg",
    "Simvastatin 20 mg",
    "Losartan 50 mg",
    "Amlodipine 5 mg",
    "Metoprolol 50 mg",
    "Warfarin 5 mg",
    "Digoxin 0.25 mg",
    "Levothyroxine 50 mcg",
    "Prednisone 5 mg",
    "Dexamethasone 0.5 mg",
    "Methotrexate 2.5 mg",
    "Cyclophosphamide 50 mg",
    "Risperidone 2 mg",
    "Olanzapine 5 mg",
    "Quetiapine 25 mg",
    "Clozapine 25 mg",
    "Haloperidol 5 mg",

    // 61-80 (Obat Bebas)
    "Calcium Carbonate 500 mg",
    "Magnesium Hydroxide 400 mg",
    "Simethicone 80 mg",
    "Dextromethorphan Syrup",
    "Guaifenesin 200 mg",
    "Pseudoephedrine Syrup",
    "Acyclovir Cream 5%",
    "Miconazole Cream 2%",
    "Clotrimazole Cream 1%",
    "Hydrocortisone Cream 1%",
    "Calamine Lotion",
    "Zinc Oxide Cream",
    "Salicylic Acid 2%",
    "Benzoyl Peroxide 5%",
    "Vitamin B Complex",
    "Vitamin E 400 IU",
    "Fish Oil 1000 mg",
    "Calcium + D3",
    "Iron + Folic Acid",
    "Multivitamin Anak",

    // 81-100 (Obat Bebas Terbatas)
    "Sildenafil 50 mg",
    "Tadalafil 20 mg",
    "Clonazepam 0.5 mg",
    "Nitrazepam 5 mg",
    "Temazepam 10 mg",
    "Zopiclone 7.5 mg",
    "Zolpidem 10 mg",
    "Modafinil 100 mg",
    "Armodafinil 150 mg",
    "Donepezil 5 mg",
    "Memantine 10 mg",
    "Rivastigmine 3 mg",
    "Galantamine 8 mg",
    "Carbamazepine 200 mg",
    "Phenytoin 100 mg",
    "Valproic Acid 250 mg",
    "Gabapentin 300 mg",
    "Pregabalin 75 mg",
    "Topiramate 25 mg",
    "Levetiracetam 500 mg",

    // 101-120 (Obat Keras)
    "Clopidogrel 75 mg",
    "Rivaroxaban 10 mg",
    "Apixaban 2.5 mg",
    "Rituximab",
    "Trastuzumab",
    "Bevacizumab",
    "Pembrolizumab",
    "Nivolumab",
    "Imatinib 100 mg",
    "Sorafenib 200 mg",
    "Lenalidomide 10 mg",
    "Thalidomide 100 mg",
    "Bortezomib 1 mg",
    "Carfilzomib",
    "Ixazomib",
    "Brentuximab Vedotin",
    "Venetoclax",
    "Ibrutinib",
    "Acyclovir IV",
    "Ganciclovir IV",

    // 121-140 (Obat Bebas)
    "Lactobacillus Capsule",
    "Saccharomyces boulardii",
    "Probiotic Kids",
    "Glucosamine 500 mg",
    "Chondroitin 400 mg",
    "Collagen Type II",
    "Evening Primrose Oil",
    "Coenzyme Q10",
    "Folic Acid 5 mg",
    "Vitamin B12 1000 mcg",
    "Vitamin K2 MK-7",
    "Magnesium Citrate",
    "Potassium Chloride",
    "Sodium Chloride IV",
    "Dextrose 5% IV",
    "Dextrose 10% IV",
    "Lactated Ringer's",
    "Normal Saline",
    "Heparin Injection",
    "Protamine Sulfate",

    // 141-160 (Obat Bebas Terbatas)
    "Meloxicam 7.5 mg",
    "Naproxen 250 mg",
    "Celecoxib 200 mg",
    "Diclofenac Sodium 50 mg",
    "Indomethacin 25 mg",
    "Piroxicam 20 mg",
    "Ketorolac 10 mg",
    "Mefenamic Acid 500 mg",
    "Chlorzoxazone 250 mg",
    "Cyclobenzaprine 5 mg",
    "Baclofen 10 mg",
    "Tizanidine 2 mg",
    "Dantrolene 25 mg",
    "Tolperisone 150 mg",
    "Eperisone 50 mg",
    "Methylprednisolone 4 mg",
    "Triamcinolone 5 mg",
    "Betamethasone 0.5 mg",
    "Clobetasol Cream",
    "Fluocinonide Cream",

    // 161-180 (Obat Keras)
    "Adalimumab",
    "Etanercept",
    "Infliximab",
    "Ustekinumab",
    "Secukinumab",
    "Ixekizumab",
    "Certolizumab Pegol",
    "Golimumab",
    "Anakinra",
    "Tocilizumab",
    "Sarilumab",
    "Baricitinib",
    "Upadacitinib",
    "Ruxolitinib",
    "Fedratinib",
    "Pomalidomide",
    "Lenalidomide Maintenance",
    "Panobinostat",
    "Vorinostat",
    "Romidepsin",

    // 181-200 (Obat Bebas & Bebas Terbatas)
    "Herbal Habbatussauda",
    "Herbal Kunyit Asam",
    "Herbal Jahe Merah",
    "Herbal Mahkota Dewa",
    "Herbal Sirih Hijau",
    "Herbal Daun Jinten",
    "Herbal Temulawak",
    "Herbal Daun Sambiloto",
    "Herbal Pegagan",
    "Herbal Daun Dewa",
    "Minyak Kayu Putih",
    "Minyak Telon",
    "Minyak Angin",
    "Koyo Plaster",
    "Plaster Bekat",
    "Koyo Anak",
    "Tetes Mata Saline",
    "Tetes Hidung Saline",
    "Obat Kumur Betadine",
    "Salep Tetracycline 3%"
};

const string FUNGSI_OBAT[JUMLAH_OBAT] = {
    // 1-20
    "Meredakan panas dan peradangan",
    "Meredakan peradangan dan nyeri",
    "Meredakan gejala kelebihan asam lambung",
    "Meredakan alergi",
    "Meredakan diare",
    "Meredakan flu dan batuk berdahak",
    "Mengatasi sakit kepala",
    "Mengobati berbagai infeksi bakteri",
    "Mengatasi infeksi bakteri",
    "Mengobati infeksi bakteri",
    "Mengurangi produksi asam lambung",
    "Mengurangi produksi asam lambung",
    "Meningkatkan daya tahan tubuh",
    "Membantu penyerapan kalsium",
    "Mendukung sistem imun",
    "Larutan Antiseptik untuk luka",
    "Meredakan iritasi pada mata",
    "Kompres penurun panas untuk orang dewasa",
    "Kompres penurun panas untuk anak-anak",
    "Kompres penurun panas untuk bayi",

    // 21-40
    "Meredakan hidung tersumbat",
    "Meredakan batuk kering",
    "Antihistamin untuk alergi",
    "Meredakan hidung tersumbat",
    "Meredakan batuk",
    "Pereda nyeri sedang hingga berat",
    "Meredakan alergi",
    "Antihistamin",
    "Meredakan asma dan bronkitis",
    "Bronkodilator untuk asma",
    "Stimulan untuk ADHD",
    "Penurun nafsu makan",
    "Obat cemas dan gangguan panik",
    "Obat cemas dan tidur",
    "Obat cemas dan gangguan tidur",
    "Obat sedatif sebelum prosedur",
    "Mengurangi asam lambung",
    "Mengurangi asam lambung",
    "Mengurangi asam lambung",
    "Mengurangi asam lambung",

    // 41-60
    "Mengontrol gula darah",
    "Mengontrol gula darah",
    "Mengontrol gula darah cepat",
    "Menurunkan kolesterol",
    "Menurunkan kolesterol",
    "Mengontrol tekanan darah",
    "Mengontrol tekanan darah",
    "Mengontrol tekanan darah",
    "Pengencer darah",
    "Mengobati gangguan jantung",
    "Menggantikan hormon tiroid",
    "Kortikosteroid anti-inflamasi",
    "Kortikosteroid anti-inflamasi",
    "Obat kanker dan autoimun",
    "Obat kanker imun",
    "Obat gangguan psikotik",
    "Obat gangguan psikotik",
    "Obat gangguan psikotik",
    "Obat gangguan psikotik",
    "Obat gangguan psikotik",

    // 61-80
    "Meredakan asam lambung",
    "Meredakan asam lambung",
    "Meredakan perut kembung",
    "Meredakan batuk",
    "Meredakan batuk berdahak",
    "Meredakan hidung tersumbat",
    "Antivirus kulit",
    "Antijamur kulit",
    "Antijamur kulit",
    "Kortikosteroid ringan",
    "Meredakan gatal dan iritasi",
    "Pelindung kulit",
    "Meredakan jerawat",
    "Meredakan jerawat",
    "Vitamin B kompleks",
    "Vitamin E untuk kulit",
    "Asam lemak omega-3",
    "Kalsium dan vitamin D",
    "Suplemen zat besi",
    "Vitamin untuk anak-anak",

    // 81-100
    "Disfungsi ereksi",
    "Disfungsi ereksi",
    "Obat cemas dan tidur",
    "Obat tidur",
    "Obat tidur",
    "Obat tidur",
    "Obat tidur",
    "Meningkatkan kewaspadaan",
    "Meningkatkan kewaspadaan",
    "Penyakit Alzheimer",
    "Penyakit Alzheimer",
    "Penyakit Alzheimer",
    "Penyakit Alzheimer",
    "Antikonvulsan",
    "Antikonvulsan",
    "Antikonvulsan",
    "Antikonvulsan",
    "Antikonvulsan",
    "Antikonvulsan",
    "Antikonvulsan",

    // 101-120
    "Pengencer darah",
    "Pengencer darah",
    "Pengencer darah",
    "Terapi kanker",
    "Terapi kanker payudara",
    "Terapi kanker kolorektal",
    "Imunoterapi kanker",
    "Imunoterapi kanker",
    "Obat kanker darah",
    "Obat kanker hati",
    "Obat kanker darah",
    "Obat kanker",
    "Obat kanker",
    "Obat kanker",
    "Obat kanker",
    "Obat kanker",
    "Obat kanker",
    "Obat kanker",
    "Antivirus IV",
    "Antivirus IV",

    // 121-140
    "Probiotik pencernaan",
    "Probiotik",
    "Probiotik untuk anak",
    "Suplemen sendi",
    "Suplemen sendi",
    "Suplemen sendi",
    "Suplemen kulit",
    "Antioksidan",
    "Suplemen asam folat",
    "Suplemen B12",
    "Suplemen K2",
    "Suplemen magnesium",
    "Suplemen kalium",
    "Infus elektrolit",
    "Infus glukosa",
    "Infus glukosa",
    "Infus cairan tubuh",
    "Infus cairan tubuh",
    "Antikoagulan IV",
    "Antidotum heparin",

    // 141-160
    "Pereda nyeri anti-inflamasi",
    "Pereda nyeri anti-inflamasi",
    "Pereda nyeri anti-inflamasi",
    "Pereda nyeri anti-inflamasi",
    "Pereda nyeri anti-inflamasi",
    "Pereda nyeri anti-inflamasi",
    "Pereda nyeri anti-inflamasi",
    "Pereda nyeri anti-inflamasi",
    "Relaksan otot",
    "Relaksan otot",
    "Relaksan otot",
    "Relaksan otot",
    "Relaksan otot",
    "Relaksan otot",
    "Relaksan otot",
    "Kortikosteroid",
    "Kortikosteroid",
    "Kortikosteroid",
    "Kortikosteroid topikal",
    "Kortikosteroid topikal",

    // 161-180
    "Terapi autoimun",
    "Terapi autoimun",
    "Terapi autoimun",
    "Terapi autoimun",
    "Terapi autoimun",
    "Terapi autoimun",
    "Terapi autoimun",
    "Terapi autoimun",
    "Terapi autoimun",
    "Terapi autoimun",
    "Terapi autoimun",
    "Terapi autoimun",
    "Terapi autoimun",
    "Terapi kanker darah",
    "Terapi kanker darah",
    "Terapi kanker",
    "Terapi kanker",
    "Terapi kanker",
    "Terapi kanker",
    "Terapi kanker",

    // 181-200
    "Herbal untuk stamina",
    "Herbal untuk pencernaan",
    "Herbal untuk pernapasan",
    "Herbal untuk darah tinggi",
    "Herbal untuk keputihan",
    "Herbal untuk pencernaan",
    "Herbal untuk hati",
    "Herbal untuk radang",
    "Herbal untuk memori",
    "Herbal untuk darah tinggi",
    "Meredakan nyeri otot",
    "Meredakan nyeri otot",
    "Meredakan nyeri perut",
    "Plaster pereda nyeri",
    "Plaster untuk bekas luka",
    "Plaster pereda nyeri anak",
    "Tetes mata pelumas",
    "Tetes hidung pelumas",
    "Obat kumur antiseptik",
    "Antibiotik topikal"
};

const int HARGA_OBAT[JUMLAH_OBAT] = {
    // 1-20
    12000, 5500, 10000, 2000, 17000,
    2500, 20000, 30000, 40000, 70000,
    25000, 4000, 18000, 20000, 20000,
    18000, 17000, 9000, 9000, 6000,

    // 21-40
    15000, 12000, 8000, 10000, 25000,
    50000, 18000, 15000, 35000, 45000,
    100000, 20000, 25000, 15000, 20000,
    25000, 25000, 20000, 30000, 35000,

    // 41-60
    15000, 200000, 250000, 25000, 20000,
    20000, 18000, 15000, 30000, 25000,
    20000, 25000, 30000, 50000, 75000,
    45000, 50000, 40000, 75000, 35000,

    // 61-80
    12000, 15000, 20000, 15000, 20000,
    15000, 30000, 25000, 20000, 20000,
    25000, 20000, 15000, 25000, 20000,
    25000, 150000, 30000, 25000, 15000,

    // 81-100
    150000, 200000, 25000, 20000, 25000,
    20000, 20000, 300000, 400000, 150000,
    200000, 150000, 180000, 150000, 120000,
    150000, 200000, 150000, 200000, 150000,

    // 101-120
    20000, 150000, 200000, 5000000, 6000000,
    7000000, 8000000, 9000000, 10000000, 12000000,
    15000000, 18000000, 20000000, 25000000, 30000000,
    35000000, 40000000, 45000000, 50000000, 55000000,

    // 121-140
    20000, 30000, 25000, 25000, 30000,
    40000, 50000, 15000, 20000, 25000,
    30000, 20000, 25000, 30000, 35000,
    40000, 45000, 50000, 100000, 150000,

    // 141-160
    20000, 15000, 25000, 20000, 25000,
    20000, 30000, 25000, 30000, 25000,
    30000, 25000, 35000, 30000, 25000,
    40000, 45000, 50000, 60000, 70000,

    // 161-180
    1000000, 1200000, 1500000, 2000000, 2500000,
    3000000, 3500000, 4000000, 4500000, 5000000,
    5500000, 6000000, 6500000, 7000000, 7500000,
    8000000, 8500000, 9000000, 9500000, 10000000,

    // 181-200
    25000, 30000, 25000, 35000, 30000,
    25000, 30000, 35000, 40000, 35000,
    15000, 12000, 10000, 18000, 20000,
    15000, 10000, 12000, 20000, 25000
};

const int STOK_AWAL_OBAT[JUMLAH_OBAT] = {
    // 1-20
    100, 100, 100, 100, 100,
    100, 100, 100, 100, 100,
    100, 100, 100, 100, 100,
    100, 100, 100, 100, 100,

    // 21-40
    100, 100, 100, 100, 100,
    100, 100, 100, 100, 100,
    100, 100, 100, 100, 100,
    100, 100, 100, 100, 100,

    // 41-60
    100, 100, 100, 100, 100,
    100, 100, 100, 100, 100,
    100, 100, 100, 100, 100,
    100, 100, 100, 100, 100,

    // 61-80
    100, 100, 100, 100, 100,
    100, 100, 100, 100, 100,
    100, 100, 100, 100, 100,
    100, 100, 100, 100, 100,

    // 81-100
    100, 100, 100, 100, 100,
    100, 100, 100, 100, 100,
    100, 100, 100, 100, 100,
    100, 100, 100, 100, 100,

    // 101-120
    100, 100, 100, 100, 100,
    100, 100, 100, 100, 100,
    100, 100, 100, 100, 100,
    100, 100, 100, 100, 100,

    // 121-140
    100, 100, 100, 100, 100,
    100, 100, 100, 100, 100,
    100, 100, 100, 100, 100,
    100, 100, 100, 100, 100,

    // 141-160
    100, 100, 100, 100, 100,
    100, 100, 100, 100, 100,
    100, 100, 100, 100, 100,
    100, 100, 100, 100, 100,

    // 161-180
    100, 100, 100, 100, 100,
    100, 100, 100, 100, 100,
    100, 100, 100, 100, 100,
    100, 100, 100, 100, 100,

    // 181-200
    100, 100, 100, 100, 100,
    100, 100, 100, 100, 100,
    100, 100, 100, 100, 100,
    100, 100, 100, 100, 100
};

// Kategori obat: 0 = Bebas, 1 = Bebas Terbatas, 2 = Keras
const int KATEGORI_OBAT[JUMLAH_OBAT] = {
    // 1-20: Bebas
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0,

    // 21-40: Bebas Terbatas
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1,

    // 41-60: Keras
    2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
    2, 2, 2, 2, 2, 2, 2, 2, 2, 2,

    // 61-80: Bebas
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0,

    // 81-100: Bebas Terbatas
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1,

    // 101-120: Keras
    2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
    2, 2, 2, 2, 2, 2, 2, 2, 2, 2,

    // 121-140: Bebas
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0,

    // 141-160: Bebas Terbatas
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1,

    // 161-180: Keras
    2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
    2, 2, 2, 2, 2, 2, 2, 2, 2, 2,

    // 181-200: Bebas / Bebas Terbatas
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0
};

#endif // DATA_OBAT_H
