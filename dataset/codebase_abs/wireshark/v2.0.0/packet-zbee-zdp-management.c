static void
F_1 ( T_1 * V_1 , T_2 * V_2 , T_3 * V_3 , T_4 V_4 )
{
T_1 * V_5 ;
T_5 * V_6 ;
T_4 V_7 ;
if ( V_4 >= V_8 ) {
V_5 = F_2 ( V_1 , V_2 , * V_3 , 12 , V_9 , NULL , L_1 ) ;
F_3 ( V_5 , V_10 , V_2 , * V_3 , 8 , V_11 ) ;
* V_3 += 8 ;
}
else {
V_5 = F_2 ( V_1 , V_2 , * V_3 , 6 , V_9 , NULL , L_1 ) ;
F_3 ( V_5 , V_12 , V_2 , * V_3 , 2 , V_11 ) ;
* V_3 += 2 ;
}
F_3 ( V_5 , V_13 , V_2 , * V_3 , 1 , V_11 ) ;
* V_3 += 1 ;
F_3 ( V_5 , V_14 , V_2 , * V_3 , 1 , V_11 ) ;
F_3 ( V_5 , V_15 , V_2 , * V_3 , 1 , V_11 ) ;
* V_3 += 1 ;
V_6 = F_3 ( V_5 , V_16 , V_2 , * V_3 , 1 , V_11 ) ;
F_3 ( V_5 , V_17 , V_2 , * V_3 , 1 , V_11 ) ;
V_7 = F_4 ( V_2 , * V_3 ) & 0x0f ;
if ( V_7 == 0xf ) {
F_5 ( V_6 , L_2 ) ;
}
* V_3 += 1 ;
F_3 ( V_5 , V_18 , V_2 , * V_3 , 1 , V_11 ) ;
* V_3 += 1 ;
}
static void
F_6 ( T_1 * V_1 , T_2 * V_2 , T_3 * V_3 , T_4 V_4 )
{
T_1 * V_19 ;
T_5 * V_6 = NULL ;
T_3 V_20 = 0 ;
if ( V_4 >= V_8 ) {
V_19 = F_2 ( V_1 , V_2 , * V_3 , 8 , V_21 , & V_6 , L_3 ) ;
F_3 ( V_19 , V_22 , V_2 , * V_3 , 8 , V_11 ) ;
V_20 += 8 ;
}
else {
V_19 = F_2 ( V_1 , V_2 , * V_3 , 2 , V_21 , & V_6 , L_3 ) ;
F_3 ( V_19 , V_12 , V_2 , * V_3 , 2 , V_11 ) ;
V_20 += 2 ;
}
F_3 ( V_19 , V_23 , V_2 , * V_3 + V_20 , 8 , V_11 ) ;
V_20 += 8 ;
F_3 ( V_19 , V_24 , V_2 , * V_3 + V_20 , 2 , V_11 ) ;
V_20 += 2 ;
if ( V_4 >= V_8 ) {
F_3 ( V_19 , V_25 , V_2 , * V_3 + V_20 , 1 , V_26 ) ;
F_3 ( V_19 , V_27 , V_2 , * V_3 + V_20 , 1 , V_26 ) ;
F_3 ( V_19 , V_28 , V_2 , * V_3 + V_20 , 1 , V_26 ) ;
}
else {
F_3 ( V_19 , V_25 , V_2 , * V_3 + V_20 , 1 , V_26 ) ;
F_3 ( V_19 , V_29 , V_2 , * V_3 + V_20 , 1 , V_26 ) ;
F_3 ( V_19 , V_30 , V_2 , * V_3 + V_20 , 1 , V_26 ) ;
}
V_20 += 1 ;
if ( V_4 <= V_31 ) {
F_3 ( V_19 , V_32 , V_2 , * V_3 + V_20 , 1 , V_26 ) ;
V_20 += 1 ;
}
F_3 ( V_19 , V_33 , V_2 , * V_3 + V_20 , 1 , V_26 ) ;
V_20 += 1 ;
if ( V_4 >= V_8 ) {
F_3 ( V_19 , V_32 , V_2 , * V_3 + V_20 , 1 , V_26 ) ;
V_20 += 1 ;
}
F_3 ( V_19 , V_34 , V_2 , * V_3 + V_20 , 1 , V_26 ) ;
V_20 += 1 ;
if ( V_1 ) F_7 ( V_6 , V_20 ) ;
* V_3 += V_20 ;
}
static void
F_8 ( T_1 * V_1 , T_2 * V_2 , T_3 * V_3 )
{
T_3 V_20 = 0 ;
T_5 * V_6 ;
T_1 * V_35 ;
T_6 V_36 ;
T_4 V_37 ;
T_6 V_38 ;
V_6 = F_3 ( V_1 , V_39 , V_2 , * V_3 + V_20 , 2 + 1 + 2 , V_26 ) ;
V_35 = F_9 ( V_6 , V_40 ) ;
F_3 ( V_35 , V_41 , V_2 , * V_3 + V_20 , 2 , V_11 ) ;
V_36 = F_10 ( V_2 , * V_3 + V_20 ) ;
V_20 += 2 ;
F_3 ( V_35 , V_42 , V_2 , * V_3 + V_20 , 1 , V_11 ) ;
V_37 = F_4 ( V_2 , * V_3 + V_20 ) ;
V_20 += 1 ;
F_3 ( V_35 , V_43 , V_2 , * V_3 + V_20 , 2 , V_11 ) ;
V_38 = F_10 ( V_2 , * V_3 + V_20 ) ;
V_20 += 2 ;
F_5 ( V_6 , L_4 , V_36 , V_38 , F_11 ( V_37 , V_44 , L_5 ) ) ;
* V_3 += V_20 ;
}
void
F_12 ( T_2 * V_2 , T_7 * V_45 , T_1 * V_1 , int V_46 )
{
T_5 * V_6 ;
T_3 V_47 ;
T_3 V_3 = 0 ;
T_8 V_48 ;
V_48 = F_13 ( V_2 , V_3 ) ;
if ( V_1 ) {
T_9 V_49 = 1 ;
V_6 = F_14 ( V_1 , V_46 , V_2 , V_3 , 4 , V_48 , L_6 ) ;
for ( V_47 = 0 ; V_47 < 27 ; V_47 ++ ) {
if ( V_48 & ( 1 << V_47 ) ) {
if ( V_49 ) F_5 ( V_6 , L_7 , V_47 ) ;
else F_5 ( V_6 , L_8 , V_47 ) ;
if ( V_48 & ( 2 << V_47 ) ) {
while ( ( V_48 & ( 2 << V_47 ) ) && ( V_47 < 26 ) ) V_47 ++ ;
F_5 ( V_6 , L_9 , V_47 ) ;
}
V_49 = 0 ;
}
}
if ( V_49 ) F_5 ( V_6 , L_10 ) ;
}
V_3 += 4 ;
F_15 ( V_1 , V_50 , V_2 , & V_3 , 1 , NULL ) ;
F_15 ( V_1 , V_51 , V_2 , & V_3 , 1 , NULL ) ;
F_16 ( V_2 , V_3 , V_45 , V_1 ) ;
}
void
F_17 ( T_2 * V_2 , T_7 * V_45 , T_1 * V_1 )
{
T_3 V_3 = 0 ;
F_15 ( V_1 , V_51 , V_2 , & V_3 , 1 , NULL ) ;
F_16 ( V_2 , V_3 , V_45 , V_1 ) ;
}
void
F_18 ( T_2 * V_2 , T_7 * V_45 , T_1 * V_1 )
{
T_3 V_3 = 0 ;
F_15 ( V_1 , V_51 , V_2 , & V_3 , 1 , NULL ) ;
F_16 ( V_2 , V_3 , V_45 , V_1 ) ;
}
void
F_19 ( T_2 * V_2 , T_7 * V_45 , T_1 * V_1 )
{
T_3 V_3 = 0 ;
F_15 ( V_1 , V_51 , V_2 , & V_3 , 1 , NULL ) ;
F_16 ( V_2 , V_3 , V_45 , V_1 ) ;
}
void
F_20 ( T_2 * V_2 , T_7 * V_45 , T_1 * V_1 , T_4 V_4 )
{
T_3 V_3 = 0 ;
T_10 V_52 ;
static const int * V_53 [] = {
& V_54 ,
& V_55 ,
NULL
} ;
V_52 = F_21 ( V_1 , V_23 , V_2 , & V_3 , 8 , NULL ) ;
if ( V_4 >= V_8 ) {
F_22 ( V_1 , V_2 , V_3 , 1 , V_53 , V_26 ) ;
V_3 += 1 ;
}
F_23 ( V_1 , V_45 , L_11 , F_24 ( F_25 () , V_52 ) ) ;
F_16 ( V_2 , V_3 , V_45 , V_1 ) ;
}
void
F_26 ( T_2 * V_2 , T_7 * V_45 , T_1 * V_1 )
{
T_3 V_3 = 0 ;
T_10 V_52 ;
V_52 = F_21 ( V_1 , V_23 , V_2 , & V_3 , 8 , NULL ) ;
F_27 ( V_1 , V_56 , V_2 , & V_3 ) ;
F_23 ( V_1 , V_45 , L_11 , F_24 ( F_25 () , V_52 ) ) ;
F_16 ( V_2 , V_3 , V_45 , V_1 ) ;
}
void
F_28 ( T_2 * V_2 , T_7 * V_45 , T_1 * V_1 )
{
T_3 V_3 = 0 ;
F_15 ( V_1 , V_50 , V_2 , & V_3 , 1 , NULL ) ;
F_15 ( V_1 , V_57 , V_2 , & V_3 , 1 , NULL ) ;
F_16 ( V_2 , V_3 , V_45 , V_1 ) ;
}
void
F_29 ( T_2 * V_2 , T_7 * V_45 , T_1 * V_1 )
{
T_3 V_3 = 0 ;
F_15 ( V_1 , V_51 , V_2 , & V_3 , 1 , NULL ) ;
F_16 ( V_2 , V_3 , V_45 , V_1 ) ;
}
void
F_30 ( T_2 * V_2 , T_7 * V_45 , T_1 * V_1 )
{
T_3 V_3 = 0 ;
T_4 V_58 ;
F_31 ( V_1 , V_2 , & V_3 , V_59 ) ;
V_58 = F_15 ( V_1 , V_50 , V_2 , & V_3 , 1 , NULL ) ;
if ( V_58 == V_60 ) {
F_15 ( V_1 , V_61 , V_2 , & V_3 , 1 , NULL ) ;
F_15 ( V_1 , V_62 , V_2 , & V_3 , 2 , NULL ) ;
}
else if ( V_58 == V_63 ) {
F_15 ( V_1 , V_61 , V_2 , & V_3 , 1 , NULL ) ;
}
else if ( V_58 <= V_64 ) {
F_15 ( V_1 , V_65 , V_2 , & V_3 , 1 , NULL ) ;
}
F_16 ( V_2 , V_3 , V_45 , V_1 ) ;
}
void
F_32 ( T_2 * V_2 , T_7 * V_45 , T_1 * V_1 , T_4 V_4 )
{
T_1 * V_35 = NULL ;
T_3 V_3 = 0 ;
T_3 V_47 ;
T_4 V_37 ;
T_4 V_66 ;
V_37 = F_33 ( V_1 , V_2 , & V_3 ) ;
F_15 ( V_1 , V_67 , V_2 , & V_3 , 1 , NULL ) ;
F_15 ( V_1 , V_51 , V_2 , & V_3 , 1 , NULL ) ;
V_66 = F_15 ( V_1 , V_68 , V_2 , & V_3 , 1 , NULL ) ;
if ( V_1 && V_66 ) {
V_35 = F_2 ( V_1 , V_2 , V_3 , - 1 , V_69 , NULL , L_12 ) ;
}
for ( V_47 = 0 ; V_47 < V_66 ; V_47 ++ ) {
F_1 ( V_35 , V_2 , & V_3 , V_4 ) ;
}
F_23 ( V_1 , V_45 , L_13 , F_34 ( V_37 ) ) ;
F_16 ( V_2 , V_3 , V_45 , V_1 ) ;
}
void
F_35 ( T_2 * V_2 , T_7 * V_45 , T_1 * V_1 , T_4 V_4 )
{
T_1 * V_35 = NULL ;
T_3 V_3 = 0 ;
T_3 V_47 ;
T_4 V_37 ;
T_4 V_66 ;
V_37 = F_33 ( V_1 , V_2 , & V_3 ) ;
F_15 ( V_1 , V_67 , V_2 , & V_3 , 1 , NULL ) ;
F_15 ( V_1 , V_51 , V_2 , & V_3 , 1 , NULL ) ;
V_66 = F_15 ( V_1 , V_68 , V_2 , & V_3 , 1 , NULL ) ;
if ( V_66 ) {
V_35 = F_2 ( V_1 , V_2 , V_3 , - 1 , V_70 , NULL , L_14 ) ;
for ( V_47 = 0 ; V_47 < V_66 ; V_47 ++ ) {
F_6 ( V_35 , V_2 , & V_3 , V_4 ) ;
}
}
F_23 ( V_1 , V_45 , L_13 , F_34 ( V_37 ) ) ;
F_16 ( V_2 , V_3 , V_45 , V_1 ) ;
}
void
F_36 ( T_2 * V_2 , T_7 * V_45 , T_1 * V_1 )
{
T_5 * V_6 ;
T_1 * V_35 = NULL ;
T_3 V_3 = 0 ;
T_3 V_47 ;
T_4 V_37 ;
T_4 V_66 ;
V_37 = F_33 ( V_1 , V_2 , & V_3 ) ;
F_15 ( V_1 , V_67 , V_2 , & V_3 , 1 , NULL ) ;
F_15 ( V_1 , V_51 , V_2 , & V_3 , 1 , NULL ) ;
V_66 = F_15 ( V_1 , V_68 , V_2 , & V_3 , 1 , NULL ) ;
if ( V_1 && V_66 ) {
V_6 = F_3 ( V_1 , V_71 , V_2 , V_3 , - 1 , V_26 ) ;
V_35 = F_9 ( V_6 , V_40 ) ;
}
for ( V_47 = 0 ; V_47 < V_66 ; V_47 ++ ) {
F_8 ( V_35 , V_2 , & V_3 ) ;
}
F_23 ( V_1 , V_45 , L_13 , F_34 ( V_37 ) ) ;
F_16 ( V_2 , V_3 , V_45 , V_1 ) ;
}
void
F_37 ( T_2 * V_2 , T_7 * V_45 , T_1 * V_1 , T_4 V_4 )
{
T_1 * V_35 = NULL ;
T_3 V_3 = 0 ;
T_3 V_47 ;
T_4 V_37 ;
T_4 V_66 ;
V_37 = F_33 ( V_1 , V_2 , & V_3 ) ;
F_15 ( V_1 , V_67 , V_2 , & V_3 , 1 , NULL ) ;
F_15 ( V_1 , V_51 , V_2 , & V_3 , 1 , NULL ) ;
V_66 = F_15 ( V_1 , V_68 , V_2 , & V_3 , 1 , NULL ) ;
if ( V_1 && V_66 ) {
V_35 = F_2 ( V_1 , V_2 , V_3 , - 1 , V_72 , NULL , L_15 ) ;
}
for ( V_47 = 0 ; V_47 < V_66 ; V_47 ++ ) {
F_38 ( V_35 , V_2 , & V_3 , V_4 ) ;
}
F_23 ( V_1 , V_45 , L_13 , F_34 ( V_37 ) ) ;
F_16 ( V_2 , V_3 , V_45 , V_1 ) ;
}
void
F_39 ( T_2 * V_2 , T_7 * V_45 , T_1 * V_1 )
{
T_3 V_3 = 0 ;
T_4 V_37 ;
V_37 = F_33 ( V_1 , V_2 , & V_3 ) ;
F_23 ( V_1 , V_45 , L_13 , F_34 ( V_37 ) ) ;
F_16 ( V_2 , V_3 , V_45 , V_1 ) ;
}
void
F_40 ( T_2 * V_2 , T_7 * V_45 , T_1 * V_1 )
{
T_3 V_3 = 0 ;
T_4 V_37 ;
V_37 = F_33 ( V_1 , V_2 , & V_3 ) ;
F_23 ( V_1 , V_45 , L_13 , F_34 ( V_37 ) ) ;
F_16 ( V_2 , V_3 , V_45 , V_1 ) ;
}
void
F_41 ( T_2 * V_2 , T_7 * V_45 , T_1 * V_1 )
{
T_3 V_3 = 0 ;
T_4 V_37 ;
V_37 = F_33 ( V_1 , V_2 , & V_3 ) ;
F_23 ( V_1 , V_45 , L_13 , F_34 ( V_37 ) ) ;
F_16 ( V_2 , V_3 , V_45 , V_1 ) ;
}
void
F_42 ( T_2 * V_2 , T_7 * V_45 , T_1 * V_1 )
{
T_1 * V_35 = NULL ;
T_1 * V_6 ;
T_3 V_3 = 0 ;
T_3 V_47 ;
T_4 V_37 ;
T_4 V_66 ;
V_37 = F_33 ( V_1 , V_2 , & V_3 ) ;
F_15 ( V_1 , V_67 , V_2 , & V_3 , 1 , NULL ) ;
F_15 ( V_1 , V_51 , V_2 , & V_3 , 1 , NULL ) ;
V_66 = F_15 ( V_1 , V_68 , V_2 , & V_3 , 1 , NULL ) ;
if ( V_66 ) {
V_35 = F_2 ( V_1 , V_2 , V_3 , V_66 * ( 2 + 8 ) ,
V_73 , NULL , L_16 ) ;
for ( V_47 = 0 ; V_47 < V_66 ; V_47 ++ ) {
T_6 V_74 = F_10 ( V_2 , V_3 + 8 ) ;
V_6 = F_3 ( V_35 , V_75 , V_2 , V_3 , 8 , V_11 ) ;
F_5 ( V_6 , L_17 , V_74 ) ;
F_7 ( V_6 , 8 + 2 ) ;
V_3 += 2 + 8 ;
}
}
F_23 ( V_1 , V_45 , L_13 , F_34 ( V_37 ) ) ;
F_16 ( V_2 , V_3 , V_45 , V_1 ) ;
}
void
F_43 ( T_2 * V_2 , T_7 * V_45 , T_1 * V_1 )
{
T_3 V_3 = 0 ;
T_3 V_47 , V_76 ;
T_8 V_48 ;
T_4 V_77 ;
F_33 ( V_1 , V_2 , & V_3 ) ;
V_48 = F_31 ( V_1 , V_2 , & V_3 , V_59 ) ;
F_15 ( V_1 , V_78 , V_2 , & V_3 , 2 , NULL ) ;
F_15 ( V_1 , V_79 , V_2 , & V_3 , 2 , NULL ) ;
V_77 = F_15 ( V_1 , V_80 , V_2 , & V_3 , 1 , NULL ) ;
for ( V_47 = 0 , V_76 = 0 ; V_47 < ( 8 * 4 ) ; V_47 ++ ) {
T_4 V_81 ;
if ( ! ( ( 1 << V_47 ) & V_48 ) ) {
continue;
}
if ( V_76 >= V_77 ) {
break;
}
V_81 = F_4 ( V_2 , V_3 ) ;
F_14 ( V_1 , V_82 , V_2 , V_3 , 1 , V_81 , L_18 , V_47 , V_81 ) ;
V_3 += 1 ;
V_76 ++ ;
}
F_16 ( V_2 , V_3 , V_45 , V_1 ) ;
}
