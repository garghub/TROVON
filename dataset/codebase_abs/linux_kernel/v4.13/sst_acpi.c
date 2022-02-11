static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
struct V_5 * V_6 = F_2 ( V_2 -> V_7 ) ;
V_4 = F_3 ( V_6 , V_8 ,
V_2 -> V_9 -> V_10 -> V_11 ) ;
if ( ! V_4 ) {
F_4 ( V_2 -> V_7 , L_1 ) ;
return - V_12 ;
}
F_5 ( V_2 -> V_7 , L_2 , ( unsigned int ) V_4 -> V_13 ,
( unsigned int ) F_6 ( V_4 ) ) ;
V_2 -> V_14 = V_4 -> V_13 + V_2 -> V_9 -> V_10 -> V_15 ;
V_2 -> V_16 = V_2 -> V_14 + V_2 -> V_9 -> V_10 -> V_17 - 1 ;
F_5 ( V_2 -> V_7 , L_3 , V_2 -> V_14 ) ;
V_2 -> V_18 = F_7 ( V_2 -> V_7 , V_2 -> V_14 ,
V_2 -> V_9 -> V_10 -> V_17 ) ;
if ( ! V_2 -> V_18 ) {
F_4 ( V_2 -> V_7 , L_4 ) ;
return - V_12 ;
}
V_2 -> V_19 = V_4 -> V_13 + V_2 -> V_9 -> V_10 -> V_20 ;
V_2 -> V_21 = V_2 -> V_19 + V_2 -> V_9 -> V_10 -> V_22 - 1 ;
F_5 ( V_2 -> V_7 , L_5 , V_2 -> V_19 ) ;
V_2 -> V_23 = F_7 ( V_2 -> V_7 , V_2 -> V_19 ,
V_2 -> V_9 -> V_10 -> V_22 ) ;
if ( ! V_2 -> V_23 ) {
F_4 ( V_2 -> V_7 , L_6 ) ;
return - V_12 ;
}
V_2 -> V_24 = V_4 -> V_13 + V_2 -> V_9 -> V_10 -> V_25 ;
F_5 ( V_2 -> V_7 , L_7 , V_2 -> V_24 ) ;
V_2 -> V_26 = F_7 ( V_2 -> V_7 , V_2 -> V_24 ,
V_2 -> V_9 -> V_10 -> V_27 ) ;
if ( ! V_2 -> V_26 ) {
F_4 ( V_2 -> V_7 , L_8 ) ;
return - V_12 ;
}
V_2 -> V_24 = V_2 -> V_9 -> V_10 -> V_28 ;
V_2 -> V_29 = V_4 -> V_13 + V_2 -> V_9 -> V_10 -> V_30 ;
F_5 ( V_2 -> V_7 , L_9 , V_2 -> V_29 ) ;
V_2 -> V_31 = F_7 ( V_2 -> V_7 , V_2 -> V_29 ,
V_2 -> V_9 -> V_10 -> V_32 ) ;
if ( ! V_2 -> V_31 ) {
F_4 ( V_2 -> V_7 , L_10 ) ;
return - V_12 ;
}
V_2 -> V_29 = V_2 -> V_33 . V_34 ;
V_4 = F_3 ( V_6 , V_8 ,
V_2 -> V_9 -> V_10 -> V_35 ) ;
if ( ! V_4 ) {
F_4 ( V_2 -> V_7 , L_11 ) ;
return - V_12 ;
}
V_2 -> V_36 = V_4 -> V_13 ;
V_2 -> V_37 = V_4 -> V_38 ;
F_5 ( V_2 -> V_7 , L_12 , V_2 -> V_36 ) ;
V_2 -> V_39 = F_7 ( V_2 -> V_7 , V_2 -> V_36 ,
F_6 ( V_4 ) ) ;
if ( ! V_2 -> V_39 ) {
F_4 ( V_2 -> V_7 , L_13 ) ;
return - V_12 ;
}
V_2 -> V_40 = F_8 ( V_6 ,
V_2 -> V_9 -> V_10 -> V_41 ) ;
return 0 ;
}
static int F_9 ( struct V_42 * V_7 , bool * V_43 )
{
int V_44 = 0 ;
if ( F_10 ( V_45 ) ) {
static const struct V_46 V_47 [] = {
{ V_48 , 6 , 55 } ,
{}
} ;
T_1 V_49 ;
if ( ! F_11 ( V_47 ) || ! F_12 () ) {
return V_44 ;
}
V_44 = F_13 ( V_50 ,
V_51 ,
0x006 ,
& V_49 ) ;
if ( V_44 ) {
F_4 ( V_7 , L_14 ) ;
} else {
V_49 = ( V_49 >> 26 ) & 3 ;
if ( ( V_49 == 1 ) || ( V_49 == 3 ) )
* V_43 = true ;
else
F_5 ( V_7 , L_15 ) ;
}
} else {
F_5 ( V_7 , L_16 ) ;
}
return V_44 ;
}
static int F_14 ( struct V_5 * V_6 )
{
struct V_42 * V_7 = & V_6 -> V_7 ;
int V_52 = 0 ;
struct V_1 * V_2 ;
const struct V_53 * V_54 ;
struct V_55 * V_56 ;
struct V_5 * V_57 ;
struct V_5 * V_58 ;
struct V_59 * V_9 ;
unsigned int V_60 ;
bool V_43 = false ;
V_54 = F_15 ( V_7 -> V_61 -> V_62 , V_7 ) ;
if ( ! V_54 )
return - V_63 ;
F_16 ( V_7 , L_17 , V_54 -> V_54 ) ;
V_56 = (struct V_55 * ) V_54 -> V_64 ;
V_56 = F_17 ( V_56 ) ;
if ( V_56 == NULL ) {
F_4 ( V_7 , L_18 ) ;
return - V_63 ;
}
V_9 = V_56 -> V_9 ;
V_52 = F_18 ( V_54 -> V_54 , 16 , & V_60 ) ;
if ( V_52 < 0 ) {
F_4 ( V_7 , L_19 , V_52 ) ;
return V_52 ;
}
F_16 ( V_7 , L_20 , V_60 ) ;
V_52 = F_19 ( & V_2 , V_7 , V_60 ) ;
if ( V_52 < 0 )
return V_52 ;
V_52 = F_9 ( V_7 , & V_43 ) ;
if ( ! ( ( V_52 < 0 ) || ( V_43 == false ) ) ) {
F_5 ( V_7 , L_21 ) ;
V_65 . V_10 = & V_66 ;
}
V_58 = F_20 ( V_7 , V_9 -> V_67 , - 1 ,
NULL , 0 ) ;
if ( F_21 ( V_58 ) ) {
F_4 ( V_7 , L_22 ,
V_9 -> V_67 ) ;
return F_22 ( V_58 ) ;
}
V_57 = F_20 ( V_7 , V_56 -> V_68 , - 1 ,
( const void * ) V_56 , sizeof( * V_56 ) ) ;
if ( F_21 ( V_57 ) ) {
F_4 ( V_7 , L_22 ,
V_56 -> V_68 ) ;
return F_22 ( V_57 ) ;
}
V_2 -> V_9 = V_9 ;
strcpy ( V_2 -> V_69 , V_56 -> V_70 ) ;
V_52 = F_1 ( V_2 ) ;
if ( V_52 )
return V_52 ;
V_52 = F_23 ( V_2 ) ;
if ( V_52 < 0 )
return V_52 ;
F_24 ( V_2 ) ;
F_25 ( V_6 , V_2 ) ;
return V_52 ;
}
static int F_26 ( struct V_5 * V_6 )
{
struct V_1 * V_2 ;
V_2 = F_27 ( V_6 ) ;
F_28 ( V_2 ) ;
F_25 ( V_6 , NULL ) ;
return 0 ;
}
static int F_29 ( const struct V_71 * V_54 )
{
V_72 = V_73 ;
return 1 ;
}
static int F_30 ( const struct V_71 * V_54 )
{
V_72 = V_74 ;
return 1 ;
}
static struct V_55 * F_31 ( void * V_75 )
{
struct V_55 * V_56 = V_75 ;
F_32 ( V_76 ) ;
if ( V_72 == V_73 )
return & V_77 ;
else
return V_56 ;
}
static struct V_55 * F_33 ( void * V_75 )
{
struct V_55 * V_56 = V_75 ;
F_32 ( V_78 ) ;
if ( V_72 == V_74 )
return & V_79 ;
else
return V_56 ;
}
