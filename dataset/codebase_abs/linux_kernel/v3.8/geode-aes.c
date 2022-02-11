static inline void
F_1 ( T_1 V_1 , void * V_2 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < 4 ; V_3 ++ )
F_2 ( ( ( T_1 * ) V_2 ) [ V_3 ] , V_4 + V_1 + ( V_3 * 4 ) ) ;
}
static inline void
F_3 ( T_1 V_1 , void * V_2 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < 4 ; V_3 ++ )
( ( T_1 * ) V_2 ) [ V_3 ] = F_4 ( V_4 + V_1 + ( V_3 * 4 ) ) ;
}
static int
F_5 ( void * V_5 , void * V_6 , int V_7 , T_1 V_8 )
{
T_1 V_9 ;
T_1 V_10 = V_11 ;
F_2 ( F_6 ( V_5 ) , V_4 + V_12 ) ;
F_2 ( F_6 ( V_6 ) , V_4 + V_13 ) ;
F_2 ( V_7 , V_4 + V_14 ) ;
F_2 ( V_15 | V_8 , V_4 + V_16 ) ;
do {
V_9 = F_4 ( V_4 + V_17 ) ;
F_7 () ;
} while ( ! ( V_9 & V_18 ) && -- V_10 );
F_2 ( ( V_9 & 0xFF ) | V_18 , V_4 + V_17 ) ;
return V_10 ? 0 : 1 ;
}
static unsigned int
F_8 ( struct V_19 * V_20 )
{
T_1 V_8 = 0 ;
unsigned long V_21 ;
int V_22 ;
if ( V_20 -> V_7 == 0 )
return 0 ;
V_8 |= ( V_23 | V_24 ) ;
if ( V_20 -> V_25 == V_26 )
V_8 |= V_27 ;
F_9 ( & V_28 , V_21 ) ;
if ( V_20 -> V_29 == V_30 ) {
V_8 |= V_31 ;
F_1 ( V_32 , V_20 -> V_33 ) ;
}
if ( ! ( V_20 -> V_8 & V_34 ) ) {
V_8 |= V_35 ;
F_1 ( V_36 , V_20 -> V_37 ) ;
}
V_22 = F_5 ( V_20 -> V_5 , V_20 -> V_6 , V_20 -> V_7 , V_8 ) ;
F_10 ( V_22 ) ;
if ( V_20 -> V_29 == V_30 )
F_3 ( V_32 , V_20 -> V_33 ) ;
F_11 ( & V_28 , V_21 ) ;
return V_20 -> V_7 ;
}
static int F_12 ( struct V_38 * V_39 , const T_2 * V_37 ,
unsigned int V_7 )
{
struct V_19 * V_20 = F_13 ( V_39 ) ;
unsigned int V_22 ;
V_20 -> V_40 = V_7 ;
if ( V_7 == V_41 ) {
memcpy ( V_20 -> V_37 , V_37 , V_7 ) ;
return 0 ;
}
if ( V_7 != V_42 && V_7 != V_43 ) {
V_39 -> V_44 |= V_45 ;
return - V_46 ;
}
V_20 -> V_47 . V_48 -> V_49 . V_44 &= ~ V_50 ;
V_20 -> V_47 . V_48 -> V_49 . V_44 |= ( V_39 -> V_44 & V_50 ) ;
V_22 = F_14 ( V_20 -> V_47 . V_48 , V_37 , V_7 ) ;
if ( V_22 ) {
V_39 -> V_44 &= ~ V_51 ;
V_39 -> V_44 |= ( V_20 -> V_47 . V_48 -> V_49 . V_44 & V_51 ) ;
}
return V_22 ;
}
static int F_15 ( struct V_38 * V_39 , const T_2 * V_37 ,
unsigned int V_7 )
{
struct V_19 * V_20 = F_13 ( V_39 ) ;
unsigned int V_22 ;
V_20 -> V_40 = V_7 ;
if ( V_7 == V_41 ) {
memcpy ( V_20 -> V_37 , V_37 , V_7 ) ;
return 0 ;
}
if ( V_7 != V_42 && V_7 != V_43 ) {
V_39 -> V_44 |= V_45 ;
return - V_46 ;
}
V_20 -> V_47 . V_52 -> V_49 . V_44 &= ~ V_50 ;
V_20 -> V_47 . V_52 -> V_49 . V_44 |= ( V_39 -> V_44 & V_50 ) ;
V_22 = F_16 ( V_20 -> V_47 . V_52 , V_37 , V_7 ) ;
if ( V_22 ) {
V_39 -> V_44 &= ~ V_51 ;
V_39 -> V_44 |= ( V_20 -> V_47 . V_52 -> V_49 . V_44 & V_51 ) ;
}
return V_22 ;
}
static int F_17 ( struct V_53 * V_54 ,
struct V_55 * V_6 , struct V_55 * V_5 ,
unsigned int V_56 )
{
unsigned int V_22 ;
struct V_57 * V_39 ;
struct V_19 * V_20 = F_18 ( V_54 -> V_39 ) ;
V_39 = V_54 -> V_39 ;
V_54 -> V_39 = V_20 -> V_47 . V_52 ;
V_22 = F_19 ( V_54 , V_6 , V_5 , V_56 ) ;
V_54 -> V_39 = V_39 ;
return V_22 ;
}
static int F_20 ( struct V_53 * V_54 ,
struct V_55 * V_6 , struct V_55 * V_5 ,
unsigned int V_56 )
{
unsigned int V_22 ;
struct V_57 * V_39 ;
struct V_19 * V_20 = F_18 ( V_54 -> V_39 ) ;
V_39 = V_54 -> V_39 ;
V_54 -> V_39 = V_20 -> V_47 . V_52 ;
V_22 = F_21 ( V_54 , V_6 , V_5 , V_56 ) ;
V_54 -> V_39 = V_39 ;
return V_22 ;
}
static void
F_22 ( struct V_38 * V_39 , T_2 * V_58 , const T_2 * V_59 )
{
struct V_19 * V_20 = F_13 ( V_39 ) ;
if ( F_23 ( V_20 -> V_40 != V_41 ) ) {
F_24 ( V_20 -> V_47 . V_48 , V_58 , V_59 ) ;
return;
}
V_20 -> V_5 = ( void * ) V_59 ;
V_20 -> V_6 = ( void * ) V_58 ;
V_20 -> V_29 = V_60 ;
V_20 -> V_8 = 0 ;
V_20 -> V_7 = V_61 ;
V_20 -> V_25 = V_26 ;
F_8 ( V_20 ) ;
}
static void
F_25 ( struct V_38 * V_39 , T_2 * V_58 , const T_2 * V_59 )
{
struct V_19 * V_20 = F_13 ( V_39 ) ;
if ( F_23 ( V_20 -> V_40 != V_41 ) ) {
F_26 ( V_20 -> V_47 . V_48 , V_58 , V_59 ) ;
return;
}
V_20 -> V_5 = ( void * ) V_59 ;
V_20 -> V_6 = ( void * ) V_58 ;
V_20 -> V_29 = V_60 ;
V_20 -> V_8 = 0 ;
V_20 -> V_7 = V_61 ;
V_20 -> V_25 = V_62 ;
F_8 ( V_20 ) ;
}
static int F_27 ( struct V_38 * V_39 )
{
const char * V_63 = V_39 -> V_64 -> V_65 ;
struct V_19 * V_20 = F_13 ( V_39 ) ;
V_20 -> V_47 . V_48 = F_28 ( V_63 , 0 ,
V_66 | V_67 ) ;
if ( F_29 ( V_20 -> V_47 . V_48 ) ) {
F_30 ( V_68 L_1 , V_63 ) ;
return F_31 ( V_20 -> V_47 . V_48 ) ;
}
return 0 ;
}
static void F_32 ( struct V_38 * V_39 )
{
struct V_19 * V_20 = F_13 ( V_39 ) ;
F_33 ( V_20 -> V_47 . V_48 ) ;
V_20 -> V_47 . V_48 = NULL ;
}
static int
F_34 ( struct V_53 * V_54 ,
struct V_55 * V_6 , struct V_55 * V_5 ,
unsigned int V_56 )
{
struct V_19 * V_20 = F_18 ( V_54 -> V_39 ) ;
struct V_69 V_70 ;
int V_71 , V_22 ;
if ( F_23 ( V_20 -> V_40 != V_41 ) )
return F_17 ( V_54 , V_6 , V_5 , V_56 ) ;
F_35 ( & V_70 , V_6 , V_5 , V_56 ) ;
V_71 = F_36 ( V_54 , & V_70 ) ;
V_20 -> V_33 = V_70 . V_33 ;
while ( ( V_56 = V_70 . V_56 ) ) {
V_20 -> V_5 = V_70 . V_5 . V_72 . V_73 ,
V_20 -> V_6 = V_70 . V_6 . V_72 . V_73 ;
V_20 -> V_29 = V_30 ;
V_20 -> V_7 = V_56 - ( V_56 % V_61 ) ;
V_20 -> V_25 = V_62 ;
V_22 = F_8 ( V_20 ) ;
V_56 -= V_22 ;
V_71 = F_37 ( V_54 , & V_70 , V_56 ) ;
}
return V_71 ;
}
static int
F_38 ( struct V_53 * V_54 ,
struct V_55 * V_6 , struct V_55 * V_5 ,
unsigned int V_56 )
{
struct V_19 * V_20 = F_18 ( V_54 -> V_39 ) ;
struct V_69 V_70 ;
int V_71 , V_22 ;
if ( F_23 ( V_20 -> V_40 != V_41 ) )
return F_20 ( V_54 , V_6 , V_5 , V_56 ) ;
F_35 ( & V_70 , V_6 , V_5 , V_56 ) ;
V_71 = F_36 ( V_54 , & V_70 ) ;
V_20 -> V_33 = V_70 . V_33 ;
while ( ( V_56 = V_70 . V_56 ) ) {
V_20 -> V_5 = V_70 . V_5 . V_72 . V_73 ,
V_20 -> V_6 = V_70 . V_6 . V_72 . V_73 ;
V_20 -> V_29 = V_30 ;
V_20 -> V_7 = V_56 - ( V_56 % V_61 ) ;
V_20 -> V_25 = V_26 ;
V_22 = F_8 ( V_20 ) ;
V_56 -= V_22 ;
V_71 = F_37 ( V_54 , & V_70 , V_56 ) ;
}
return V_71 ;
}
static int F_39 ( struct V_38 * V_39 )
{
const char * V_63 = V_39 -> V_64 -> V_65 ;
struct V_19 * V_20 = F_13 ( V_39 ) ;
V_20 -> V_47 . V_52 = F_40 ( V_63 , 0 ,
V_66 | V_67 ) ;
if ( F_29 ( V_20 -> V_47 . V_52 ) ) {
F_30 ( V_68 L_1 , V_63 ) ;
return F_31 ( V_20 -> V_47 . V_52 ) ;
}
return 0 ;
}
static void F_41 ( struct V_38 * V_39 )
{
struct V_19 * V_20 = F_13 ( V_39 ) ;
F_42 ( V_20 -> V_47 . V_52 ) ;
V_20 -> V_47 . V_52 = NULL ;
}
static int
F_43 ( struct V_53 * V_54 ,
struct V_55 * V_6 , struct V_55 * V_5 ,
unsigned int V_56 )
{
struct V_19 * V_20 = F_18 ( V_54 -> V_39 ) ;
struct V_69 V_70 ;
int V_71 , V_22 ;
if ( F_23 ( V_20 -> V_40 != V_41 ) )
return F_17 ( V_54 , V_6 , V_5 , V_56 ) ;
F_35 ( & V_70 , V_6 , V_5 , V_56 ) ;
V_71 = F_36 ( V_54 , & V_70 ) ;
while ( ( V_56 = V_70 . V_56 ) ) {
V_20 -> V_5 = V_70 . V_5 . V_72 . V_73 ,
V_20 -> V_6 = V_70 . V_6 . V_72 . V_73 ;
V_20 -> V_29 = V_60 ;
V_20 -> V_7 = V_56 - ( V_56 % V_61 ) ;
V_20 -> V_25 = V_62 ;
V_22 = F_8 ( V_20 ) ;
V_56 -= V_22 ;
V_71 = F_37 ( V_54 , & V_70 , V_56 ) ;
}
return V_71 ;
}
static int
F_44 ( struct V_53 * V_54 ,
struct V_55 * V_6 , struct V_55 * V_5 ,
unsigned int V_56 )
{
struct V_19 * V_20 = F_18 ( V_54 -> V_39 ) ;
struct V_69 V_70 ;
int V_71 , V_22 ;
if ( F_23 ( V_20 -> V_40 != V_41 ) )
return F_20 ( V_54 , V_6 , V_5 , V_56 ) ;
F_35 ( & V_70 , V_6 , V_5 , V_56 ) ;
V_71 = F_36 ( V_54 , & V_70 ) ;
while ( ( V_56 = V_70 . V_56 ) ) {
V_20 -> V_5 = V_70 . V_5 . V_72 . V_73 ,
V_20 -> V_6 = V_70 . V_6 . V_72 . V_73 ;
V_20 -> V_29 = V_60 ;
V_20 -> V_7 = V_56 - ( V_56 % V_61 ) ;
V_20 -> V_25 = V_26 ;
V_22 = F_8 ( V_20 ) ;
V_56 -= V_22 ;
V_22 = F_37 ( V_54 , & V_70 , V_56 ) ;
}
return V_71 ;
}
static void F_45 ( struct V_74 * V_75 )
{
F_46 ( & V_76 ) ;
F_46 ( & V_77 ) ;
F_46 ( & V_78 ) ;
F_47 ( V_75 , V_4 ) ;
V_4 = NULL ;
F_48 ( V_75 ) ;
F_49 ( V_75 ) ;
}
static int F_50 ( struct V_74 * V_75 , const struct V_79 * V_80 )
{
int V_22 ;
V_22 = F_51 ( V_75 ) ;
if ( V_22 )
return V_22 ;
V_22 = F_52 ( V_75 , L_2 ) ;
if ( V_22 )
goto V_81;
V_4 = F_53 ( V_75 , 0 , 0 ) ;
if ( V_4 == NULL ) {
V_22 = - V_82 ;
goto V_83;
}
F_54 ( & V_28 ) ;
F_2 ( V_84 | V_85 , V_4 + V_17 ) ;
V_22 = F_55 ( & V_76 ) ;
if ( V_22 )
goto V_86;
V_22 = F_55 ( & V_77 ) ;
if ( V_22 )
goto V_87;
V_22 = F_55 ( & V_78 ) ;
if ( V_22 )
goto V_88;
F_30 ( V_89 L_3 ) ;
return 0 ;
V_88:
F_46 ( & V_77 ) ;
V_87:
F_46 ( & V_76 ) ;
V_86:
F_47 ( V_75 , V_4 ) ;
V_83:
F_48 ( V_75 ) ;
V_81:
F_49 ( V_75 ) ;
F_30 ( V_68 L_4 ) ;
return V_22 ;
}
