static char * F_1 ( unsigned V_1 )
{
switch ( V_1 ) {
case V_2 :
return L_1 ;
case V_3 :
return L_2 ;
case V_4 :
return L_3 ;
case V_5 :
return L_4 ;
case V_6 :
return L_5 ;
case V_7 :
return L_6 ;
case V_8 :
return L_7 ;
default:
return L_8 ;
}
}
static int F_2 ( char * V_9 , int V_10 , struct V_11 * V_12 )
{
volatile struct V_13 * V_14 = V_12 -> V_15 ;
volatile struct V_13 * V_16 = V_12 -> V_17 ;
return F_3 (
V_9 , V_10 ,
L_9
L_10
L_11 , V_12 -> V_1 ,
F_1 ( V_14 -> V_18 ) , V_14 -> V_19 , V_14 -> V_20 ,
V_14 -> V_21 ? 'D' : 'd' ,
V_14 -> V_22 ? 'C' : 'c' ,
V_14 -> V_23 ? 'C' : 'c' ,
V_14 -> V_24 ? 'I' : 'i' ,
V_14 -> V_25 ? 'W' : 'w' ,
V_14 -> V_26 ? 'R' : 'r' ,
V_14 -> V_27 ? 'S' : 's' ,
F_1 ( V_16 -> V_18 ) , V_16 -> V_19 , V_16 -> V_20 ,
V_16 -> V_21 ? 'D' : 'd' ,
V_16 -> V_22 ? 'R' : 'r' ,
V_16 -> V_23 ? 'C' : 'c' ,
V_16 -> V_24 ? 'I' : 'i' ,
V_16 -> V_25 ? 'W' : 'w' ,
V_16 -> V_26 ? 'R' : 'r' ,
V_16 -> V_27 ? 'S' : 's' ,
V_12 -> V_28
) ;
}
static int F_4 ( char * V_9 , int V_10 )
{
char * V_29 ;
int V_30 = 0 ;
V_29 = F_5 ( V_31 , V_32 ) ;
if ( F_6 ( V_33 ) & V_34 )
V_30 += F_3 ( V_9 + V_30 , V_10 - V_30 ,
L_12 ) ;
V_30 += F_3 ( V_9 + V_30 , V_10 - V_30 , L_13 ,
F_6 ( V_33 ) ,
F_6 ( V_35 ) ) ;
#ifdef F_7
V_30 += F_3 ( V_9 + V_30 , V_10 - V_30 , L_14
L_15 ,
F_6 ( V_36 ) ,
F_6 ( V_37 ) ,
F_6 ( V_38 ) ,
F_6 ( V_39 ) ,
F_6 ( V_40 ) ) ;
#endif
if ( V_29 ) {
V_29 [ V_32 - 1 ] = 0 ;
V_30 += F_3 ( V_9 + V_30 , V_10 - V_30 , L_16 , V_29 ) ;
}
return V_30 ;
}
static int F_8 ( char * V_9 , int V_10 )
{
unsigned V_1 ;
struct V_41 * V_42 = ( void * ) V_43 ;
struct V_44 * V_45 = V_42 -> V_46 ;
int V_30 = 0 ;
V_30 += F_3 ( V_9 + V_30 , V_10 - V_30 ,
L_17 ,
V_42 -> V_47 . V_48 ,
V_42 -> V_47 . V_49 ,
V_42 -> V_47 . V_50 ) ;
for ( V_1 = 0 ; V_1 < V_51 ; V_1 ++ ) {
if ( V_45 [ V_1 ] . V_52 == 0 )
continue;
V_30 += F_3 ( V_9 + V_30 , V_10 - V_30 ,
L_18 ,
V_1 , V_45 [ V_1 ] . V_53 , V_45 [ V_1 ] . V_54 ) ;
}
return V_30 ;
}
static int F_9 ( char * V_9 , int V_10 )
{
struct V_11 * V_12 ;
unsigned long V_55 ;
int V_30 = 0 ;
F_10 ( & V_56 , V_55 ) ;
F_11 (ch, &smd_ch_list_dsp, ch_list)
V_30 += F_2 ( V_9 + V_30 , V_10 - V_30 , V_12 ) ;
F_11 (ch, &smd_ch_list_modem, ch_list)
V_30 += F_2 ( V_9 + V_30 , V_10 - V_30 , V_12 ) ;
F_11 (ch, &smd_ch_closed_list, ch_list)
V_30 += F_2 ( V_9 + V_30 , V_10 - V_30 , V_12 ) ;
F_12 ( & V_56 , V_55 ) ;
return V_30 ;
}
static int F_13 ( char * V_9 , int V_10 )
{
struct V_41 * V_42 = ( void * ) V_43 ;
unsigned V_57 = V_42 -> V_57 [ V_58 ] ;
return sprintf ( V_9 , L_19 , V_57 >> 16 , V_57 & 0xffff ) ;
}
static int F_14 ( char * V_9 , int V_10 )
{
unsigned V_54 ;
void * V_59 ;
V_59 = F_15 ( V_60 , & V_54 ) ;
if ( ! V_59 )
return 0 ;
if ( V_54 >= V_10 )
V_54 = V_10 ;
memcpy ( V_9 , V_59 , V_54 ) ;
return V_54 ;
}
static int F_16 ( char * V_9 , int V_10 )
{
struct V_61 * V_42 ;
int V_1 , V_30 = 0 ;
V_42 = F_5 ( V_62 , sizeof( * V_42 ) * 64 ) ;
for ( V_1 = 0 ; V_1 < 64 ; V_1 ++ ) {
if ( V_42 [ V_1 ] . V_63 == 0 )
continue;
V_30 += F_3 ( V_9 + V_30 , V_10 - V_30 ,
L_20
L_21 ,
V_1 , V_42 [ V_1 ] . V_28 , V_42 [ V_1 ] . V_64 ,
V_42 [ V_1 ] . V_65 & 0xff ,
( V_42 [ V_1 ] . V_65 >> 8 ) & 0xf ,
V_42 [ V_1 ] . V_63 ) ;
}
return V_30 ;
}
static T_1 F_17 ( struct V_66 * V_66 , char T_2 * V_9 ,
T_3 V_67 , T_4 * V_68 )
{
int (* F_18)( char * V_9 , int V_10 ) = V_66 -> V_69 ;
int V_70 = F_18 ( V_71 , V_72 ) ;
return F_19 ( V_9 , V_67 , V_68 , V_71 , V_70 ) ;
}
static int F_20 ( struct V_73 * V_73 , struct V_66 * V_66 )
{
V_66 -> V_69 = V_73 -> V_74 ;
return 0 ;
}
static void F_21 ( const char * V_28 , T_5 V_75 ,
struct V_76 * V_77 ,
int (* F_18)( char * V_9 , int V_10 ) )
{
F_22 ( V_28 , V_75 , V_77 , F_18 , & V_78 ) ;
}
static int F_23 ( void )
{
struct V_76 * V_77 ;
V_77 = F_24 ( L_22 , 0 ) ;
if ( F_25 ( V_77 ) )
return 1 ;
F_21 ( L_23 , 0444 , V_77 , F_9 ) ;
F_21 ( L_24 , 0444 , V_77 , F_4 ) ;
F_21 ( L_25 , 0444 , V_77 , F_8 ) ;
F_21 ( L_26 , 0444 , V_77 , F_13 ) ;
F_21 ( L_27 , 0444 , V_77 , F_16 ) ;
F_21 ( L_28 , 0444 , V_77 , F_14 ) ;
return 0 ;
}
void F_26 ( void )
{
unsigned long V_55 ;
T_6 * V_79 ;
#ifndef F_7
struct V_80 * V_81 ;
struct V_82 * V_83 ;
#endif
F_10 ( & V_84 , V_55 ) ;
V_79 = F_27 ( V_85 , sizeof( * V_79 ) ) ;
if ( V_79 )
F_28 ( L_29 , * V_79 ) ;
V_79 = F_27 ( V_86 , sizeof( * V_79 ) ) ;
if ( V_79 )
F_28 ( L_30 , * V_79 ) ;
V_79 = F_27 ( V_87 , sizeof( * V_79 ) ) ;
if ( V_79 )
F_28 ( L_31 , * V_79 ) ;
#ifndef F_7
V_83 = F_27 ( V_88 , sizeof( * V_83 ) ) ;
if ( V_83 )
F_28 ( L_32 ,
V_83 -> V_89 ,
V_83 -> V_90 ,
V_83 -> V_91 ) ;
V_81 = F_27 ( V_92 , sizeof( * V_81 ) ) ;
if ( V_81 ) {
int V_30 ;
for ( V_30 = 0 ; V_30 < V_93 ; V_30 ++ )
F_28 ( L_33 ,
V_30 , V_81 -> V_94 [ V_30 ] , V_81 -> V_95 [ V_30 ] ,
V_81 -> V_96 [ V_30 ] ) ;
for ( V_30 = 0 ; V_30 < V_97 ; V_30 ++ )
F_28 ( L_34 ,
V_30 , V_81 -> V_98 [ V_30 ] , V_81 -> V_99 [ V_30 ] [ 0 ] ,
V_81 -> V_99 [ V_30 ] [ 1 ] ) ;
}
#else
#endif
F_12 ( & V_84 , V_55 ) ;
}
