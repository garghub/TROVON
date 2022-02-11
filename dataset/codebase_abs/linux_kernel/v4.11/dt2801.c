static int F_1 ( struct V_1 * V_2 , int * V_3 )
{
int V_4 = 0 ;
int V_5 = V_6 ;
do {
V_4 = F_2 ( V_2 -> V_7 + V_8 ) ;
if ( V_4 & ( V_9 | V_10 ) )
return V_4 ;
if ( V_4 & V_11 ) {
* V_3 = F_2 ( V_2 -> V_7 + V_12 ) ;
return 0 ;
}
} while ( -- V_5 > 0 );
return - V_13 ;
}
static int F_3 ( struct V_1 * V_2 , int * V_3 )
{
int V_14 = 0 ;
int V_15 = 0 ;
int V_16 ;
V_16 = F_1 ( V_2 , & V_14 ) ;
if ( V_16 )
return V_16 ;
V_16 = F_1 ( V_2 , & V_15 ) ;
if ( V_16 )
return V_16 ;
* V_3 = ( V_15 << 8 ) + V_14 ;
return 0 ;
}
static int F_4 ( struct V_1 * V_2 , unsigned int V_3 )
{
int V_4 = 0 ;
int V_5 = V_6 ;
do {
V_4 = F_2 ( V_2 -> V_7 + V_8 ) ;
if ( V_4 & V_9 )
return V_4 ;
if ( ! ( V_4 & V_17 ) ) {
F_5 ( V_3 & 0xff , V_2 -> V_7 + V_12 ) ;
return 0 ;
}
} while ( -- V_5 > 0 );
return - V_13 ;
}
static int F_6 ( struct V_1 * V_2 , unsigned int V_3 )
{
int V_16 ;
V_16 = F_4 ( V_2 , V_3 & 0xff ) ;
if ( V_16 < 0 )
return V_16 ;
V_16 = F_4 ( V_2 , V_3 >> 8 ) ;
if ( V_16 < 0 )
return V_16 ;
return 0 ;
}
static int F_7 ( struct V_1 * V_2 )
{
int V_5 = V_6 ;
int V_4 ;
V_4 = F_2 ( V_2 -> V_7 + V_8 ) ;
if ( V_4 & V_10 )
return 0 ;
do {
V_4 = F_2 ( V_2 -> V_7 + V_8 ) ;
if ( V_4 & V_9 )
return V_4 ;
if ( V_4 & V_10 )
return 0 ;
} while ( -- V_5 > 0 );
return - V_13 ;
}
static void F_8 ( struct V_1 * V_2 , int V_18 )
{
int V_4 ;
F_7 ( V_2 ) ;
V_4 = F_2 ( V_2 -> V_7 + V_8 ) ;
if ( V_4 & V_9 ) {
F_9 ( V_2 -> V_19 ,
L_1 , V_20 ) ;
}
if ( ! ( V_4 & V_10 ) )
F_9 ( V_2 -> V_19 , L_2 , V_20 ) ;
F_5 ( V_18 , V_2 -> V_7 + V_21 ) ;
}
static int F_10 ( struct V_1 * V_2 )
{
int V_22 = 0 ;
unsigned int V_4 ;
int V_5 ;
F_2 ( V_2 -> V_7 + V_12 ) ;
F_2 ( V_2 -> V_7 + V_12 ) ;
F_2 ( V_2 -> V_7 + V_12 ) ;
F_2 ( V_2 -> V_7 + V_12 ) ;
F_5 ( V_23 , V_2 -> V_7 + V_21 ) ;
F_11 ( 100 , 200 ) ;
V_5 = 10000 ;
do {
V_4 = F_2 ( V_2 -> V_7 + V_8 ) ;
if ( V_4 & V_10 )
break;
} while ( V_5 -- );
if ( ! V_5 )
F_9 ( V_2 -> V_19 , L_3 , V_4 ) ;
F_5 ( V_24 , V_2 -> V_7 + V_21 ) ;
F_11 ( 100 , 200 ) ;
V_5 = 10000 ;
do {
V_4 = F_2 ( V_2 -> V_7 + V_8 ) ;
if ( V_4 & V_10 )
break;
} while ( V_5 -- );
if ( ! V_5 )
F_9 ( V_2 -> V_19 , L_4 , V_4 ) ;
F_1 ( V_2 , & V_22 ) ;
return V_22 ;
}
static int F_12 ( struct V_1 * V_2 )
{
int V_25 ;
int V_4 ;
int V_3 ;
for ( V_25 = 0 ; V_25 < 16 ; V_25 ++ ) {
F_8 ( V_2 , V_26 ) ;
F_4 ( V_2 , 0 ) ;
F_4 ( V_2 , V_25 ) ;
V_4 = F_3 ( V_2 , & V_3 ) ;
if ( V_4 )
break;
}
F_10 ( V_2 ) ;
F_10 ( V_2 ) ;
return V_25 ;
}
static const struct V_27 * F_13 ( int V_28 )
{
if ( V_28 < 0 || V_28 >= 5 )
return & V_29 ;
return V_30 [ V_28 ] ;
}
static const struct V_27 * F_14 ( int type , int V_28 )
{
switch ( type ) {
case 0 :
return ( V_28 ) ?
& V_31 :
& V_32 ;
case 1 :
return ( V_28 ) ? & V_33 : & V_34 ;
case 2 :
return & V_35 ;
}
return & V_29 ;
}
static int F_15 ( struct V_1 * V_2 , int V_4 )
{
if ( V_4 < 0 ) {
if ( V_4 == - V_13 )
F_9 ( V_2 -> V_19 , L_5 ) ;
else
F_9 ( V_2 -> V_19 , L_6 , V_4 ) ;
return V_4 ;
}
F_9 ( V_2 -> V_19 , L_7 , V_4 ) ;
F_10 ( V_2 ) ;
F_10 ( V_2 ) ;
return - V_36 ;
}
static int F_16 ( struct V_1 * V_2 ,
struct V_37 * V_38 ,
struct V_39 * V_40 , unsigned int * V_3 )
{
int V_41 ;
int V_4 ;
int V_42 ;
for ( V_42 = 0 ; V_42 < V_40 -> V_43 ; V_42 ++ ) {
F_8 ( V_2 , V_26 ) ;
F_4 ( V_2 , F_17 ( V_40 -> V_44 ) ) ;
F_4 ( V_2 , F_18 ( V_40 -> V_44 ) ) ;
V_4 = F_3 ( V_2 , & V_41 ) ;
if ( V_4 != 0 )
return F_15 ( V_2 , V_4 ) ;
V_3 [ V_42 ] = V_41 ;
}
return V_42 ;
}
static int F_19 ( struct V_1 * V_2 ,
struct V_37 * V_38 ,
struct V_39 * V_40 ,
unsigned int * V_3 )
{
unsigned int V_45 = F_18 ( V_40 -> V_44 ) ;
F_8 ( V_2 , V_46 ) ;
F_4 ( V_2 , V_45 ) ;
F_6 ( V_2 , V_3 [ 0 ] ) ;
V_38 -> V_47 [ V_45 ] = V_3 [ 0 ] ;
return 1 ;
}
static int F_20 ( struct V_1 * V_2 ,
struct V_37 * V_38 ,
struct V_39 * V_40 ,
unsigned int * V_3 )
{
int V_48 = ( V_38 == & V_2 -> V_49 [ 3 ] ) ? 1 : 0 ;
unsigned int V_50 = 0 ;
if ( F_21 ( V_38 , V_3 ) ) {
F_8 ( V_2 , V_51 ) ;
F_4 ( V_2 , V_48 ) ;
F_4 ( V_2 , V_38 -> V_52 ) ;
}
F_8 ( V_2 , V_53 ) ;
F_4 ( V_2 , V_48 ) ;
F_1 ( V_2 , & V_50 ) ;
V_3 [ 1 ] = V_50 ;
return V_40 -> V_43 ;
}
static int F_22 ( struct V_1 * V_2 ,
struct V_37 * V_38 ,
struct V_39 * V_40 ,
unsigned int * V_3 )
{
int V_16 ;
V_16 = F_23 ( V_2 , V_38 , V_40 , V_3 , 0xff ) ;
if ( V_16 )
return V_16 ;
F_8 ( V_2 , V_38 -> V_54 ? V_55 : V_56 ) ;
F_4 ( V_2 , ( V_38 == & V_2 -> V_49 [ 3 ] ) ? 1 : 0 ) ;
return V_40 -> V_43 ;
}
static int F_24 ( struct V_1 * V_2 , struct V_57 * V_58 )
{
const struct V_59 * V_60 ;
struct V_61 * V_62 ;
struct V_37 * V_38 ;
int V_22 , type ;
int V_16 = 0 ;
int V_63 ;
V_16 = F_25 ( V_2 , V_58 -> V_64 [ 0 ] , 0x2 ) ;
if ( V_16 )
return V_16 ;
V_22 = F_10 ( V_2 ) ;
if ( ! V_22 )
V_22 = F_10 ( V_2 ) ;
for ( type = 0 ; type < F_26 ( V_65 ) ; type ++ ) {
if ( V_65 [ type ] . V_66 == V_22 )
goto V_67;
}
F_9 ( V_2 -> V_19 ,
L_8 , V_22 ) ;
type = 0 ;
V_67:
V_2 -> V_68 = V_65 + type ;
V_60 = V_2 -> V_68 ;
V_63 = F_12 ( V_2 ) ;
V_16 = F_27 ( V_2 , 4 ) ;
if ( V_16 )
goto V_69;
V_62 = F_28 ( V_2 , sizeof( * V_62 ) ) ;
if ( ! V_62 )
return - V_70 ;
V_2 -> V_71 = V_60 -> V_72 ;
V_38 = & V_2 -> V_49 [ 0 ] ;
V_38 -> type = V_73 ;
V_38 -> V_74 = V_75 | V_76 ;
#if 1
V_38 -> V_77 = V_63 ;
#else
if ( V_58 -> V_64 [ 2 ] )
V_38 -> V_77 = V_60 -> V_78 ;
else
V_38 -> V_77 = V_60 -> V_78 / 2 ;
#endif
V_38 -> V_79 = ( 1 << V_60 -> V_80 ) - 1 ;
V_38 -> V_81 = F_14 ( V_60 -> V_82 , V_58 -> V_64 [ 3 ] ) ;
V_38 -> V_83 = F_16 ;
V_38 = & V_2 -> V_49 [ 1 ] ;
V_38 -> type = V_84 ;
V_38 -> V_74 = V_85 ;
V_38 -> V_77 = 2 ;
V_38 -> V_79 = ( 1 << V_60 -> V_86 ) - 1 ;
V_38 -> V_87 = V_62 -> V_88 ;
V_62 -> V_88 [ 0 ] = F_13 ( V_58 -> V_64 [ 4 ] ) ;
V_62 -> V_88 [ 1 ] = F_13 ( V_58 -> V_64 [ 5 ] ) ;
V_38 -> V_89 = F_19 ;
V_16 = F_29 ( V_38 ) ;
if ( V_16 )
return V_16 ;
V_38 = & V_2 -> V_49 [ 2 ] ;
V_38 -> type = V_90 ;
V_38 -> V_74 = V_75 | V_85 ;
V_38 -> V_77 = 8 ;
V_38 -> V_79 = 1 ;
V_38 -> V_81 = & V_91 ;
V_38 -> V_92 = F_20 ;
V_38 -> V_93 = F_22 ;
V_38 = & V_2 -> V_49 [ 3 ] ;
V_38 -> type = V_90 ;
V_38 -> V_74 = V_75 | V_85 ;
V_38 -> V_77 = 8 ;
V_38 -> V_79 = 1 ;
V_38 -> V_81 = & V_91 ;
V_38 -> V_92 = F_20 ;
V_38 -> V_93 = F_22 ;
V_16 = 0 ;
V_69:
return V_16 ;
}
