int F_1 ( char * V_1 , char * * V_2 ,
T_1 V_3 , int V_4 ,
int * V_5 , void * V_6 )
{
int V_7 = 0 ;
V_7 += snprintf ( V_1 + V_7 , V_4 - V_7 , L_1 , V_8 ) ;
* V_5 = 1 ;
return V_7 ;
}
int F_2 ( char * V_1 , char * * V_2 ,
T_1 V_3 , int V_4 ,
int * V_5 , void * V_6 )
{
* V_5 = 1 ;
return 0 ;
}
int F_3 ( struct V_9 * V_9 , const char T_2 * V_10 ,
unsigned long V_4 , void * V_6 )
{
struct V_11 * V_12 = (struct V_11 * ) V_6 ;
struct V_13 * V_14 = (struct V_13 * ) F_4 ( V_12 ) ;
char V_15 [ 32 ] ;
T_3 V_16 , V_17 , V_7 ;
if ( V_4 < 3 ) {
F_5 ( L_2 ) ;
return - V_18 ;
}
if ( V_10 && ! F_6 ( V_15 , V_10 , sizeof( V_15 ) ) ) {
int V_19 = sscanf ( V_15 , L_3 , & V_16 , & V_17 , & V_7 ) ;
if ( V_19 != 3 ) {
F_5 ( L_4 ) ;
return V_4 ;
}
switch ( V_7 ) {
case 1 :
F_7 ( V_14 , V_16 , ( V_20 ) V_17 ) ;
break;
case 2 :
F_8 ( V_14 , V_16 , ( V_21 ) V_17 ) ;
break;
case 4 :
F_9 ( V_14 , V_16 , V_17 ) ;
break;
default:
F_5 ( L_5 , V_7 ) ;
break;
}
}
return V_4 ;
}
int F_10 ( char * V_1 , char * * V_2 ,
T_1 V_3 , int V_4 ,
int * V_5 , void * V_6 )
{
struct V_11 * V_12 = V_6 ;
struct V_13 * V_14 = (struct V_13 * ) F_4 ( V_12 ) ;
int V_7 = 0 ;
if ( V_22 == 0xeeeeeeee ) {
* V_5 = 1 ;
return V_7 ;
}
switch ( V_23 ) {
case 1 :
V_7 += snprintf ( V_1 + V_7 , V_4 - V_7 , L_6 , V_22 , F_11 ( V_14 , V_22 ) ) ;
break;
case 2 :
V_7 += snprintf ( V_1 + V_7 , V_4 - V_7 , L_7 , V_22 , F_12 ( V_14 , V_22 ) ) ;
break;
case 4 :
V_7 += snprintf ( V_1 + V_7 , V_4 - V_7 , L_8 , V_22 , F_13 ( V_14 , V_22 ) ) ;
break;
default:
V_7 += snprintf ( V_1 + V_7 , V_4 - V_7 , L_9 , V_23 ) ;
break;
}
* V_5 = 1 ;
return V_7 ;
}
int F_14 ( struct V_9 * V_9 , const char T_2 * V_10 ,
unsigned long V_4 , void * V_6 )
{
char V_15 [ 16 ] ;
T_3 V_16 , V_7 ;
if ( V_4 < 2 ) {
F_5 ( L_10 ) ;
return - V_18 ;
}
if ( V_10 && ! F_6 ( V_15 , V_10 , sizeof( V_15 ) ) ) {
int V_19 = sscanf ( V_15 , L_11 , & V_16 , & V_7 ) ;
if ( V_19 != 2 ) {
F_5 ( L_12 ) ;
return V_4 ;
}
V_22 = V_16 ;
V_23 = V_7 ;
}
return V_4 ;
}
int F_15 ( char * V_1 , char * * V_2 ,
T_1 V_3 , int V_4 ,
int * V_5 , void * V_6 )
{
struct V_11 * V_12 = V_6 ;
struct V_13 * V_14 = (struct V_13 * ) F_4 ( V_12 ) ;
struct V_24 * V_25 = & ( V_14 -> V_26 ) ;
int V_7 = 0 ;
V_7 += snprintf ( V_1 + V_7 , V_4 - V_7 , L_13 , F_16 ( V_25 ) ) ;
* V_5 = 1 ;
return V_7 ;
}
int F_17 ( char * V_1 , char * * V_2 ,
T_1 V_3 , int V_4 ,
int * V_5 , void * V_6 )
{
struct V_11 * V_12 = V_6 ;
struct V_13 * V_14 = (struct V_13 * ) F_4 ( V_12 ) ;
struct V_27 * V_28 = & V_14 -> V_29 ;
int V_7 = 0 ;
V_7 += snprintf ( V_1 + V_7 , V_4 - V_7 , L_14 ,
V_28 -> V_30 , V_28 -> V_31 ,
V_28 -> V_32 , V_28 -> V_33 ) ;
* V_5 = 1 ;
return V_7 ;
}
int F_18 ( char * V_1 , char * * V_2 ,
T_1 V_3 , int V_4 ,
int * V_5 , void * V_6 )
{
struct V_11 * V_12 = V_6 ;
struct V_13 * V_14 = (struct V_13 * ) F_4 ( V_12 ) ;
struct V_34 * V_35 = & V_14 -> V_36 ;
struct V_37 * V_38 = & ( V_35 -> V_39 ) ;
int V_7 = 0 ;
V_7 += snprintf ( V_1 + V_7 , V_4 - V_7 , L_15 , V_38 -> V_40 ) ;
* V_5 = 1 ;
return V_7 ;
}
int F_19 ( char * V_1 , char * * V_2 ,
T_1 V_3 , int V_4 ,
int * V_5 , void * V_6 )
{
struct V_11 * V_12 = V_6 ;
struct V_13 * V_14 = (struct V_13 * ) F_4 ( V_12 ) ;
struct V_24 * V_25 = & ( V_14 -> V_26 ) ;
int V_7 = 0 ;
V_7 += snprintf ( V_1 + V_7 , V_4 - V_7 , L_16 , V_25 -> V_41 . V_42 ) ;
* V_5 = 1 ;
return V_7 ;
}
int F_20 ( char * V_1 , char * * V_2 ,
T_1 V_3 , int V_4 ,
int * V_5 , void * V_6 )
{
struct V_11 * V_12 = V_6 ;
struct V_13 * V_14 = (struct V_13 * ) F_4 ( V_12 ) ;
struct V_24 * V_25 = & ( V_14 -> V_26 ) ;
int V_7 = 0 ;
V_7 += snprintf ( V_1 + V_7 , V_4 - V_7 , L_17 , V_25 -> V_43 . V_44 ) ;
* V_5 = 1 ;
return V_7 ;
}
int F_21 ( char * V_1 , char * * V_2 ,
T_1 V_3 , int V_4 ,
int * V_5 , void * V_6 )
{
struct V_11 * V_12 = V_6 ;
struct V_13 * V_14 = (struct V_13 * ) F_4 ( V_12 ) ;
struct V_34 * V_35 = & V_14 -> V_36 ;
int V_7 = 0 ;
V_7 += snprintf ( V_1 + V_7 , V_4 - V_7 , L_18 ,
V_35 -> V_45 , V_35 -> V_46 , V_35 -> V_47 ) ;
* V_5 = 1 ;
return V_7 ;
}
int F_22 ( char * V_1 , char * * V_2 ,
T_1 V_3 , int V_4 ,
int * V_5 , void * V_6 )
{
struct V_48 * V_49 ;
struct V_11 * V_12 = V_6 ;
struct V_13 * V_14 = (struct V_13 * ) F_4 ( V_12 ) ;
struct V_24 * V_25 = & ( V_14 -> V_26 ) ;
struct V_34 * V_35 = & V_14 -> V_36 ;
struct V_50 * V_51 = & ( V_25 -> V_51 ) ;
struct V_52 * V_53 = & V_14 -> V_54 ;
int V_7 = 0 ;
V_49 = F_23 ( V_53 , V_51 -> V_55 . V_56 ) ;
if ( V_49 ) {
int V_57 ;
struct V_58 * V_59 ;
V_7 += snprintf ( V_1 + V_7 , V_4 - V_7 , L_19 , V_51 -> V_55 . V_60 . V_60 ) ;
V_7 += snprintf ( V_1 + V_7 , V_4 - V_7 , L_20 , V_49 -> V_61 ) ;
V_7 += snprintf ( V_1 + V_7 , V_4 - V_7 , L_21 , V_35 -> V_45 , V_35 -> V_46 , V_35 -> V_47 ) ;
V_7 += snprintf ( V_1 + V_7 , V_4 - V_7 , L_22 , V_49 -> V_62 , V_49 -> V_63 ) ;
V_7 += snprintf ( V_1 + V_7 , V_4 - V_7 , L_23 , V_49 -> V_40 , V_49 -> V_64 , V_49 -> V_65 , V_49 -> V_66 ) ;
V_7 += snprintf ( V_1 + V_7 , V_4 - V_7 , L_24 , V_49 -> V_42 , V_49 -> V_43 . V_44 , V_49 -> V_67 ) ;
V_7 += snprintf ( V_1 + V_7 , V_4 - V_7 , L_25 , V_49 -> V_43 . V_68 , V_49 -> V_43 . V_69 , V_49 -> V_43 . V_70 ) ;
V_7 += snprintf ( V_1 + V_7 , V_4 - V_7 , L_26 , V_49 -> V_43 . V_71 ) ;
V_7 += snprintf ( V_1 + V_7 , V_4 - V_7 , L_27 , V_49 -> V_43 . V_72 , V_49 -> V_43 . V_73 ) ;
for ( V_57 = 0 ; V_57 < 16 ; V_57 ++ ) {
V_59 = & V_49 -> V_74 [ V_57 ] ;
if ( V_59 -> V_75 )
V_7 += snprintf ( V_1 + V_7 , V_4 - V_7 , L_28 , V_57 , V_59 -> V_76 ) ;
}
} else {
V_7 += snprintf ( V_1 + V_7 , V_4 - V_7 , L_29 , V_51 -> V_55 . V_56 ) ;
}
* V_5 = 1 ;
return V_7 ;
}
int F_24 ( char * V_1 , char * * V_2 ,
T_1 V_3 , int V_4 ,
int * V_5 , void * V_6 )
{
struct V_11 * V_12 = V_6 ;
struct V_13 * V_14 = (struct V_13 * ) F_4 ( V_12 ) ;
int V_7 = 0 ;
V_7 += snprintf ( V_1 + V_7 , V_4 - V_7 , L_30 ,
V_14 -> V_77 , V_14 -> V_78 ) ;
* V_5 = 1 ;
return V_7 ;
}
int F_25 ( char * V_1 , char * * V_2 ,
T_1 V_3 , int V_4 ,
int * V_5 , void * V_6 )
{
struct V_11 * V_12 = V_6 ;
struct V_13 * V_14 = (struct V_13 * ) F_4 ( V_12 ) ;
struct V_79 * V_80 = & V_14 -> V_81 ;
struct V_82 * V_83 = & V_14 -> V_84 ;
int V_7 = 0 ;
V_7 += snprintf ( V_1 + V_7 , V_4 - V_7 , L_31 ,
V_80 -> V_85 , V_80 -> V_86 , V_80 -> V_87 , V_83 -> V_88 ) ;
V_7 += snprintf ( V_1 + V_7 , V_4 - V_7 , L_32 , V_83 -> V_89 ) ;
* V_5 = 1 ;
return V_7 ;
}
int F_26 ( char * V_1 , char * * V_2 ,
T_1 V_3 , int V_4 ,
int * V_5 , void * V_6 )
{
struct V_11 * V_12 = V_6 ;
struct V_13 * V_14 = (struct V_13 * ) F_4 ( V_12 ) ;
int V_7 = 0 ;
int V_57 , V_90 = 1 ;
V_7 += snprintf ( V_1 + V_7 , V_4 - V_7 , L_33 ) ;
for ( V_57 = 0x0 ; V_57 < 0x300 ; V_57 += 4 ) {
if ( V_90 % 4 == 1 )
V_7 += snprintf ( V_1 + V_7 , V_4 - V_7 , L_34 , V_57 ) ;
V_7 += snprintf ( V_1 + V_7 , V_4 - V_7 , L_35 , F_13 ( V_14 , V_57 ) ) ;
if ( ( V_90 ++ ) % 4 == 0 )
V_7 += snprintf ( V_1 + V_7 , V_4 - V_7 , L_36 ) ;
}
* V_5 = 1 ;
return V_7 ;
}
int F_27 ( char * V_1 , char * * V_2 ,
T_1 V_3 , int V_4 ,
int * V_5 , void * V_6 )
{
struct V_11 * V_12 = V_6 ;
struct V_13 * V_14 = (struct V_13 * ) F_4 ( V_12 ) ;
int V_7 = 0 ;
int V_57 , V_90 = 1 ;
V_7 += snprintf ( V_1 + V_7 , V_4 - V_7 , L_33 ) ;
memset ( V_1 , 0 , V_4 ) ;
for ( V_57 = 0x300 ; V_57 < 0x600 ; V_57 += 4 ) {
if ( V_90 % 4 == 1 )
V_7 += snprintf ( V_1 + V_7 , V_4 - V_7 , L_34 , V_57 ) ;
V_7 += snprintf ( V_1 + V_7 , V_4 - V_7 , L_35 , F_13 ( V_14 , V_57 ) ) ;
if ( ( V_90 ++ ) % 4 == 0 )
V_7 += snprintf ( V_1 + V_7 , V_4 - V_7 , L_36 ) ;
}
* V_5 = 1 ;
return V_7 ;
}
int F_28 ( char * V_1 , char * * V_2 ,
T_1 V_3 , int V_4 ,
int * V_5 , void * V_6 )
{
struct V_11 * V_12 = V_6 ;
struct V_13 * V_14 = (struct V_13 * ) F_4 ( V_12 ) ;
int V_7 = 0 ;
int V_57 , V_90 = 1 ;
V_7 += snprintf ( V_1 + V_7 , V_4 - V_7 , L_33 ) ;
for ( V_57 = 0x600 ; V_57 < 0x800 ; V_57 += 4 ) {
if ( V_90 % 4 == 1 )
V_7 += snprintf ( V_1 + V_7 , V_4 - V_7 , L_34 , V_57 ) ;
V_7 += snprintf ( V_1 + V_7 , V_4 - V_7 , L_35 , F_13 ( V_14 , V_57 ) ) ;
if ( ( V_90 ++ ) % 4 == 0 )
V_7 += snprintf ( V_1 + V_7 , V_4 - V_7 , L_36 ) ;
}
* V_5 = 1 ;
return V_7 ;
}
int F_29 ( char * V_1 , char * * V_2 ,
T_1 V_3 , int V_4 ,
int * V_5 , void * V_6 )
{
struct V_11 * V_12 = V_6 ;
struct V_13 * V_14 = (struct V_13 * ) F_4 ( V_12 ) ;
int V_7 = 0 ;
int V_57 , V_90 = 1 ;
V_7 += snprintf ( V_1 + V_7 , V_4 - V_7 , L_37 ) ;
for ( V_57 = 0x800 ; V_57 < 0xB00 ; V_57 += 4 ) {
if ( V_90 % 4 == 1 )
V_7 += snprintf ( V_1 + V_7 , V_4 - V_7 , L_34 , V_57 ) ;
V_7 += snprintf ( V_1 + V_7 , V_4 - V_7 , L_35 , F_13 ( V_14 , V_57 ) ) ;
if ( ( V_90 ++ ) % 4 == 0 )
V_7 += snprintf ( V_1 + V_7 , V_4 - V_7 , L_36 ) ;
}
* V_5 = 1 ;
return V_7 ;
}
int F_30 ( char * V_1 , char * * V_2 ,
T_1 V_3 , int V_4 ,
int * V_5 , void * V_6 )
{
struct V_11 * V_12 = V_6 ;
struct V_13 * V_14 = (struct V_13 * ) F_4 ( V_12 ) ;
int V_7 = 0 ;
int V_57 , V_90 = 1 ;
V_7 += snprintf ( V_1 + V_7 , V_4 - V_7 , L_37 ) ;
for ( V_57 = 0xB00 ; V_57 < 0xE00 ; V_57 += 4 ) {
if ( V_90 % 4 == 1 )
V_7 += snprintf ( V_1 + V_7 , V_4 - V_7 , L_34 , V_57 ) ;
V_7 += snprintf ( V_1 + V_7 , V_4 - V_7 , L_35 , F_13 ( V_14 , V_57 ) ) ;
if ( ( V_90 ++ ) % 4 == 0 )
V_7 += snprintf ( V_1 + V_7 , V_4 - V_7 , L_36 ) ;
}
* V_5 = 1 ;
return V_7 ;
}
int F_31 ( char * V_1 , char * * V_2 ,
T_1 V_3 , int V_4 ,
int * V_5 , void * V_6 )
{
struct V_11 * V_12 = V_6 ;
struct V_13 * V_14 = (struct V_13 * ) F_4 ( V_12 ) ;
int V_7 = 0 ;
int V_57 , V_90 = 1 ;
V_7 += snprintf ( V_1 + V_7 , V_4 - V_7 , L_37 ) ;
for ( V_57 = 0xE00 ; V_57 < 0x1000 ; V_57 += 4 ) {
if ( V_90 % 4 == 1 )
V_7 += snprintf ( V_1 + V_7 , V_4 - V_7 , L_34 , V_57 ) ;
V_7 += snprintf ( V_1 + V_7 , V_4 - V_7 , L_35 , F_13 ( V_14 , V_57 ) ) ;
if ( ( V_90 ++ ) % 4 == 0 )
V_7 += snprintf ( V_1 + V_7 , V_4 - V_7 , L_36 ) ;
}
* V_5 = 1 ;
return V_7 ;
}
int F_32 ( char * V_1 , char * * V_2 ,
T_1 V_3 , int V_4 ,
int * V_5 , void * V_6 )
{
struct V_11 * V_12 = V_6 ;
struct V_13 * V_14 = (struct V_13 * ) F_4 ( V_12 ) ;
int V_7 = 0 ;
int V_57 , V_90 = 1 , V_91 ;
T_3 V_92 ;
V_7 += snprintf ( V_1 + V_7 , V_4 - V_7 , L_38 ) ;
V_91 = 1 ;
V_7 += snprintf ( V_1 + V_7 , V_4 - V_7 , L_39 , V_91 ) ;
for ( V_57 = 0 ; V_57 < 0xC0 ; V_57 ++ ) {
V_92 = F_33 ( V_14 , V_91 , V_57 , 0xffffffff ) ;
if ( V_90 % 4 == 1 )
V_7 += snprintf ( V_1 + V_7 , V_4 - V_7 , L_40 , V_57 ) ;
V_7 += snprintf ( V_1 + V_7 , V_4 - V_7 , L_35 , V_92 ) ;
if ( ( V_90 ++ ) % 4 == 0 )
V_7 += snprintf ( V_1 + V_7 , V_4 - V_7 , L_36 ) ;
}
* V_5 = 1 ;
return V_7 ;
}
int F_34 ( char * V_1 , char * * V_2 ,
T_1 V_3 , int V_4 ,
int * V_5 , void * V_6 )
{
struct V_11 * V_12 = V_6 ;
struct V_13 * V_14 = (struct V_13 * ) F_4 ( V_12 ) ;
int V_7 = 0 ;
int V_57 , V_90 = 1 , V_91 ;
T_3 V_92 ;
V_7 += snprintf ( V_1 + V_7 , V_4 - V_7 , L_38 ) ;
V_91 = 1 ;
V_7 += snprintf ( V_1 + V_7 , V_4 - V_7 , L_39 , V_91 ) ;
for ( V_57 = 0xC0 ; V_57 < 0x100 ; V_57 ++ ) {
V_92 = F_33 ( V_14 , V_91 , V_57 , 0xffffffff ) ;
if ( V_90 % 4 == 1 )
V_7 += snprintf ( V_1 + V_7 , V_4 - V_7 , L_40 , V_57 ) ;
V_7 += snprintf ( V_1 + V_7 , V_4 - V_7 , L_35 , V_92 ) ;
if ( ( V_90 ++ ) % 4 == 0 )
V_7 += snprintf ( V_1 + V_7 , V_4 - V_7 , L_36 ) ;
}
* V_5 = 1 ;
return V_7 ;
}
int F_35 ( char * V_1 , char * * V_2 ,
T_1 V_3 , int V_4 ,
int * V_5 , void * V_6 )
{
struct V_11 * V_12 = V_6 ;
struct V_13 * V_14 = (struct V_13 * ) F_4 ( V_12 ) ;
int V_7 = 0 ;
int V_57 , V_90 = 1 , V_91 ;
T_3 V_92 ;
V_7 += snprintf ( V_1 + V_7 , V_4 - V_7 , L_38 ) ;
V_91 = 2 ;
V_7 += snprintf ( V_1 + V_7 , V_4 - V_7 , L_39 , V_91 ) ;
for ( V_57 = 0 ; V_57 < 0xC0 ; V_57 ++ ) {
V_92 = F_33 ( V_14 , V_91 , V_57 , 0xffffffff ) ;
if ( V_90 % 4 == 1 )
V_7 += snprintf ( V_1 + V_7 , V_4 - V_7 , L_40 , V_57 ) ;
V_7 += snprintf ( V_1 + V_7 , V_4 - V_7 , L_35 , V_92 ) ;
if ( ( V_90 ++ ) % 4 == 0 )
V_7 += snprintf ( V_1 + V_7 , V_4 - V_7 , L_36 ) ;
}
* V_5 = 1 ;
return V_7 ;
}
int F_36 ( char * V_1 , char * * V_2 ,
T_1 V_3 , int V_4 ,
int * V_5 , void * V_6 )
{
struct V_11 * V_12 = V_6 ;
struct V_13 * V_14 = (struct V_13 * ) F_4 ( V_12 ) ;
int V_7 = 0 ;
int V_57 , V_90 = 1 , V_91 ;
T_3 V_92 ;
V_7 += snprintf ( V_1 + V_7 , V_4 - V_7 , L_38 ) ;
V_91 = 2 ;
V_7 += snprintf ( V_1 + V_7 , V_4 - V_7 , L_39 , V_91 ) ;
for ( V_57 = 0xC0 ; V_57 < 0x100 ; V_57 ++ ) {
V_92 = F_33 ( V_14 , V_91 , V_57 , 0xffffffff ) ;
if ( V_90 % 4 == 1 )
V_7 += snprintf ( V_1 + V_7 , V_4 - V_7 , L_40 , V_57 ) ;
V_7 += snprintf ( V_1 + V_7 , V_4 - V_7 , L_35 , V_92 ) ;
if ( ( V_90 ++ ) % 4 == 0 )
V_7 += snprintf ( V_1 + V_7 , V_4 - V_7 , L_36 ) ;
}
* V_5 = 1 ;
return V_7 ;
}
int F_37 ( char * V_1 , char * * V_2 ,
T_1 V_3 , int V_4 ,
int * V_5 , void * V_6 )
{
struct V_11 * V_12 = V_6 ;
struct V_13 * V_14 = (struct V_13 * ) F_4 ( V_12 ) ;
int V_7 = 0 ;
V_7 = snprintf ( V_1 + V_7 , V_4 ,
L_41
L_42
L_43
L_44
L_45 ,
V_14 -> V_84 . V_93 ,
V_14 -> V_84 . V_94 ,
V_14 -> V_84 . V_95 ,
V_14 -> V_84 . V_96 ,
V_14 -> V_84 . V_97
) ;
* V_5 = 1 ;
return V_7 ;
}
int F_38 ( struct V_9 * V_9 , const char T_2 * V_10 ,
unsigned long V_4 , void * V_6 )
{
struct V_11 * V_12 = (struct V_11 * ) V_6 ;
struct V_13 * V_14 = (struct V_13 * ) F_4 ( V_12 ) ;
char V_15 [ 32 ] ;
T_3 V_98 ;
T_4 V_95 ;
if ( V_4 < 1 )
return - V_18 ;
if ( V_10 && ! F_6 ( V_15 , V_10 , sizeof( V_15 ) ) ) {
int V_19 = sscanf ( V_15 , L_46 , & V_98 , & V_95 ) ;
V_98 = V_98 == 0 ? 0 : 1 ;
if ( V_98 && V_19 != 2 )
return V_4 ;
V_95 = V_95 > 100 ? 100 : V_95 ;
V_95 = V_95 < 0 ? 0 : V_95 ;
V_14 -> V_84 . V_98 = V_98 ;
V_14 -> V_84 . V_99 = V_95 ;
if ( V_98 )
F_5 ( L_47 , L_48 , V_95 ) ;
else
F_5 ( L_49 , L_50 ) ;
}
return V_4 ;
}
int F_39 ( char * V_1 , char * * V_2 ,
T_1 V_3 , int V_4 ,
int * V_5 , void * V_6 )
{
struct V_11 * V_12 = V_6 ;
struct V_13 * V_14 = (struct V_13 * ) F_4 ( V_12 ) ;
struct V_100 * V_101 = & V_14 -> V_102 ;
int V_7 = 0 ;
if ( V_101 )
V_7 += snprintf ( V_1 + V_7 , V_4 - V_7 ,
L_51 ,
V_101 -> V_103
) ;
* V_5 = 1 ;
return V_7 ;
}
int F_40 ( struct V_9 * V_9 , const char T_2 * V_10 ,
unsigned long V_4 , void * V_6 )
{
struct V_11 * V_12 = (struct V_11 * ) V_6 ;
struct V_13 * V_14 = (struct V_13 * ) F_4 ( V_12 ) ;
struct V_100 * V_101 = & V_14 -> V_102 ;
char V_15 [ 32 ] ;
T_4 V_104 = 0 ;
if ( V_4 < 1 )
return - V_18 ;
if ( V_10 && ! F_6 ( V_15 , V_10 , sizeof( V_15 ) ) ) {
if ( V_101 ) {
V_101 -> V_103 = V_104 ;
F_41 ( L_52 , V_101 -> V_103 ) ;
}
}
return V_4 ;
}
int F_42 ( char * V_1 , char * * V_2 ,
T_1 V_3 , int V_4 ,
int * V_5 , void * V_6 )
{
struct V_11 * V_12 = V_6 ;
struct V_13 * V_14 = (struct V_13 * ) F_4 ( V_12 ) ;
struct V_100 * V_101 = & V_14 -> V_102 ;
int V_7 = 0 ;
if ( V_101 )
V_7 += snprintf ( V_1 + V_7 , V_4 - V_7 ,
L_51 ,
V_101 -> V_105
) ;
* V_5 = 1 ;
return V_7 ;
}
int F_43 ( struct V_9 * V_9 , const char T_2 * V_10 ,
unsigned long V_4 , void * V_6 )
{
struct V_11 * V_12 = (struct V_11 * ) V_6 ;
struct V_13 * V_14 = (struct V_13 * ) F_4 ( V_12 ) ;
struct V_100 * V_101 = & V_14 -> V_102 ;
char V_15 [ 32 ] ;
T_4 V_104 = 0 ;
if ( V_4 < 1 )
return - V_18 ;
if ( V_10 && ! F_6 ( V_15 , V_10 , sizeof( V_15 ) ) ) {
if ( V_101 ) {
V_101 -> V_105 = V_104 ;
F_41 ( L_53 , V_104 ) ;
}
}
return V_4 ;
}
int F_44 ( char * V_1 , char * * V_2 ,
T_1 V_3 , int V_4 ,
int * V_5 , void * V_6 )
{
struct V_11 * V_12 = V_6 ;
struct V_13 * V_14 = (struct V_13 * ) F_4 ( V_12 ) ;
struct V_100 * V_101 = & V_14 -> V_102 ;
int V_7 = 0 ;
if ( V_101 )
V_7 += snprintf ( V_1 + V_7 , V_4 - V_7 ,
L_51 ,
V_101 -> V_71
) ;
* V_5 = 1 ;
return V_7 ;
}
int F_45 ( struct V_9 * V_9 , const char T_2 * V_10 ,
unsigned long V_4 , void * V_6 )
{
struct V_11 * V_12 = (struct V_11 * ) V_6 ;
struct V_13 * V_14 = (struct V_13 * ) F_4 ( V_12 ) ;
struct V_100 * V_101 = & V_14 -> V_102 ;
char V_15 [ 32 ] ;
T_4 V_104 = 0 ;
if ( V_4 < 1 )
return - V_18 ;
if ( V_10 && ! F_6 ( V_15 , V_10 , sizeof( V_15 ) ) ) {
if ( V_101 ) {
V_101 -> V_71 = V_104 ;
F_41 ( L_54 , V_104 ) ;
}
}
return V_4 ;
}
int F_46 ( char * V_1 , char * * V_2 ,
T_1 V_3 , int V_4 ,
int * V_5 , void * V_6 )
{
struct V_11 * V_12 = V_6 ;
struct V_13 * V_14 = (struct V_13 * ) F_4 ( V_12 ) ;
int V_7 = 0 ;
if ( V_14 )
V_7 += snprintf ( V_1 + V_7 , V_4 - V_7 ,
L_55 ,
V_14 -> V_84 . V_106 [ 0 ] ,
V_14 -> V_84 . V_106 [ 1 ]
) ;
* V_5 = 1 ;
return V_7 ;
}
int F_47 ( char * V_1 , char * * V_2 ,
T_1 V_3 , int V_4 ,
int * V_5 , void * V_6 )
{
struct V_11 * V_12 = V_6 ;
struct V_13 * V_14 = (struct V_13 * ) F_4 ( V_12 ) ;
struct V_100 * V_101 = & V_14 -> V_102 ;
int V_7 = 0 ;
if ( V_101 )
V_7 += snprintf ( V_1 + V_7 , V_4 - V_7 ,
L_51 ,
V_101 -> V_107
) ;
* V_5 = 1 ;
return V_7 ;
}
int F_48 ( struct V_9 * V_9 , const char T_2 * V_10 ,
unsigned long V_4 , void * V_6 )
{
struct V_11 * V_12 = (struct V_11 * ) V_6 ;
struct V_13 * V_14 = (struct V_13 * ) F_4 ( V_12 ) ;
struct V_100 * V_101 = & V_14 -> V_102 ;
char V_15 [ 32 ] ;
T_3 V_104 = 0 ;
if ( V_4 < 1 )
return - V_18 ;
if ( V_10 && ! F_6 ( V_15 , V_10 , sizeof( V_15 ) ) ) {
if ( V_101 ) {
V_101 -> V_107 = V_104 ;
F_49 ( V_12 , L_56 , V_104 ) ;
}
}
return V_4 ;
}
int F_50 ( char * V_1 , char * * V_2 ,
T_1 V_3 , int V_4 ,
int * V_5 , void * V_6 )
{
* V_5 = 1 ;
return 0 ;
}
int F_51 ( struct V_9 * V_9 , const char T_2 * V_10 ,
unsigned long V_4 , void * V_6 )
{
struct V_11 * V_12 = (struct V_11 * ) V_6 ;
struct V_13 * V_14 = (struct V_13 * ) F_4 ( V_12 ) ;
char V_15 [ 32 ] ;
T_3 V_75 = 0 ;
if ( V_4 < 1 ) {
F_5 ( L_57 ) ;
return - V_18 ;
}
if ( V_10 && ! F_6 ( V_15 , V_10 , sizeof( V_15 ) ) ) {
int V_19 = sscanf ( V_15 , L_58 , & V_75 ) ;
if ( V_19 != 1 ) {
F_5 ( L_59 ) ;
return V_4 ;
}
if ( V_75 ) {
F_5 ( L_60 ) ;
V_14 -> V_108 = V_75 ;
} else {
F_5 ( L_61 ) ;
V_14 -> V_108 = 0 ;
}
}
return V_4 ;
}
int F_52 ( char * V_1 , char * * V_2 ,
T_1 V_3 , int V_4 ,
int * V_5 , void * V_6 )
{
struct V_48 * V_49 ;
struct V_11 * V_12 = V_6 ;
struct V_13 * V_14 = (struct V_13 * ) F_4 ( V_12 ) ;
struct V_52 * V_53 = & V_14 -> V_54 ;
int V_57 , V_90 ;
struct V_109 * V_110 , * V_111 ;
struct V_58 * V_59 ;
int V_7 = 0 ;
V_7 += snprintf ( V_1 + V_7 , V_4 - V_7 , L_62 , V_53 -> V_112 , V_53 -> V_113 ) ;
F_53 ( & V_53 -> V_114 ) ;
for ( V_57 = 0 ; V_57 < V_115 ; V_57 ++ ) {
V_111 = & ( V_53 -> V_116 [ V_57 ] ) ;
V_110 = V_111 -> V_117 ;
while ( V_111 != V_110 ) {
V_49 = F_54 ( V_110 , struct V_48 , V_118 ) ;
V_110 = V_110 -> V_117 ;
V_7 += snprintf ( V_1 + V_7 , V_4 - V_7 , L_63 , V_49 -> V_61 ) ;
V_7 += snprintf ( V_1 + V_7 , V_4 - V_7 , L_22 , V_49 -> V_62 , V_49 -> V_63 ) ;
V_7 += snprintf ( V_1 + V_7 , V_4 - V_7 , L_23 , V_49 -> V_40 , V_49 -> V_64 , V_49 -> V_65 , V_49 -> V_66 ) ;
V_7 += snprintf ( V_1 + V_7 , V_4 - V_7 , L_24 , V_49 -> V_42 , V_49 -> V_43 . V_44 , V_49 -> V_67 ) ;
V_7 += snprintf ( V_1 + V_7 , V_4 - V_7 , L_25 , V_49 -> V_43 . V_68 , V_49 -> V_43 . V_69 , V_49 -> V_43 . V_70 ) ;
V_7 += snprintf ( V_1 + V_7 , V_4 - V_7 , L_26 , V_49 -> V_43 . V_71 ) ;
V_7 += snprintf ( V_1 + V_7 , V_4 - V_7 , L_27 , V_49 -> V_43 . V_72 , V_49 -> V_43 . V_73 ) ;
V_7 += snprintf ( V_1 + V_7 , V_4 - V_7 , L_64 , V_49 -> V_119 ) ;
V_7 += snprintf ( V_1 + V_7 , V_4 - V_7 , L_65 , V_49 -> V_120 ) ;
V_7 += snprintf ( V_1 + V_7 , V_4 - V_7 , L_66 , V_49 -> V_121 ) ;
V_7 += snprintf ( V_1 + V_7 , V_4 - V_7 , L_67 , V_49 -> V_122 ) ;
V_7 += snprintf ( V_1 + V_7 , V_4 - V_7 , L_68 , V_49 -> V_123 ) ;
V_7 += snprintf ( V_1 + V_7 , V_4 - V_7 , L_69 , V_49 -> V_124 ) ;
V_7 += snprintf ( V_1 + V_7 , V_4 - V_7 , L_70 , V_49 -> V_125 ) ;
V_7 += snprintf ( V_1 + V_7 , V_4 - V_7 , L_71 , V_49 -> V_126 ) ;
for ( V_90 = 0 ; V_90 < 16 ; V_90 ++ ) {
V_59 = & V_49 -> V_74 [ V_90 ] ;
if ( V_59 -> V_75 )
V_7 += snprintf ( V_1 + V_7 , V_4 - V_7 , L_28 , V_90 , V_59 -> V_76 ) ;
}
}
}
F_55 ( & V_53 -> V_114 ) ;
* V_5 = 1 ;
return V_7 ;
}
int F_56 ( char * V_1 , char * * V_2 ,
T_1 V_3 , int V_4 ,
int * V_5 , void * V_6 )
{
struct V_11 * V_12 = V_6 ;
struct V_13 * V_14 = (struct V_13 * ) F_4 ( V_12 ) ;
struct V_34 * V_35 = & V_14 -> V_36 ;
int V_7 = 0 ;
T_3 V_57 , V_127 = 1 , V_128 = 36 , V_129 = 0 , V_130 = 0 ;
for ( V_57 = 0 ; V_35 -> V_131 [ V_57 ] . V_132 != 0 ; V_57 ++ ) {
if ( V_35 -> V_131 [ V_57 ] . V_132 == 1 )
V_129 = V_57 ;
if ( V_35 -> V_131 [ V_57 ] . V_132 == 36 )
V_130 = V_57 ;
}
for ( V_57 = 0 ; V_35 -> V_131 [ V_57 ] . V_132 != 0 ; V_57 ++ ) {
if ( V_35 -> V_131 [ V_57 ] . V_132 == 6 ) {
if ( V_35 -> V_131 [ V_57 ] . V_133 < V_35 -> V_131 [ V_129 ] . V_133 ) {
V_129 = V_57 ;
V_127 = V_35 -> V_131 [ V_57 ] . V_132 ;
}
}
if ( V_35 -> V_131 [ V_57 ] . V_132 >= 36 &&
V_35 -> V_131 [ V_57 ] . V_132 < 140 ) {
if ( ( ( V_35 -> V_131 [ V_57 ] . V_132 - 36 ) % 8 == 0 ) &&
( V_35 -> V_131 [ V_57 ] . V_133 < V_35 -> V_131 [ V_130 ] . V_133 ) ) {
V_130 = V_57 ;
V_128 = V_35 -> V_131 [ V_57 ] . V_132 ;
}
}
if ( V_35 -> V_131 [ V_57 ] . V_132 >= 149 &&
V_35 -> V_131 [ V_57 ] . V_132 < 165 ) {
if ( ( ( V_35 -> V_131 [ V_57 ] . V_132 - 149 ) % 8 == 0 ) &&
( V_35 -> V_131 [ V_57 ] . V_133 < V_35 -> V_131 [ V_130 ] . V_133 ) ) {
V_130 = V_57 ;
V_128 = V_35 -> V_131 [ V_57 ] . V_132 ;
}
}
V_7 += snprintf ( V_1 + V_7 , V_4 - V_7 , L_72 ,
V_35 -> V_131 [ V_57 ] . V_132 , V_35 -> V_131 [ V_57 ] . V_133 ) ;
}
V_7 += snprintf ( V_1 + V_7 , V_4 - V_7 , L_73 , V_128 ) ;
V_7 += snprintf ( V_1 + V_7 , V_4 - V_7 , L_74 , V_127 ) ;
* V_5 = 1 ;
return V_7 ;
}
