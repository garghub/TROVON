static inline T_1 F_1 ( T_1 V_1 , int type )
{
T_1 V_2 = V_3 ;
if ( type & V_4 )
V_2 |= V_5 ;
if ( type & V_6 )
V_2 |= V_7 ;
if ( type & V_8 )
V_2 |= V_9 ;
return ( V_1 << V_10 ) | V_2 ;
}
T_2 * F_2 ( struct V_11 * V_12 , struct V_13 * V_14 )
{
struct V_15 * V_16 = V_12 -> V_17 ;
unsigned long V_18 ;
V_18 = V_14 -> V_19 . V_20 - V_16 -> V_21 -> V_20 ;
return V_16 -> V_22 + ( V_18 >> V_10 ) ;
}
static int F_3 ( struct V_11 * V_12 , struct V_13 * V_14 )
{
T_2 * V_23 , V_24 ;
struct V_25 * * V_26 ;
int V_27 ;
if ( V_14 -> V_26 == NULL ) {
F_4 ( 1 ) ;
return - V_28 ;
}
F_4 ( V_14 -> V_29 ) ;
V_23 = F_2 ( V_12 , V_14 ) ;
V_26 = V_14 -> V_26 ;
F_5 ( V_26 , V_14 -> V_30 ) ;
for ( V_27 = V_14 -> V_31 ; V_27 < V_14 -> V_30 ; V_27 ++ ) {
V_24 = F_1 ( F_6 ( V_14 -> V_26 [ V_27 ] ) , 0 ) ;
F_7 ( V_24 , V_23 ++ ) ;
}
for ( V_27 = 0 ; V_27 < V_14 -> V_31 ; V_27 ++ ) {
V_24 = F_1 ( F_6 ( V_14 -> V_26 [ V_27 ] ) , 0 ) ;
F_7 ( V_24 , V_23 ++ ) ;
}
F_8 ( V_23 - 1 ) ;
return 0 ;
}
static void F_9 ( struct V_11 * V_12 , struct V_13 * V_14 )
{
struct V_15 * V_16 = V_12 -> V_17 ;
T_2 * V_23 , V_24 ;
int V_27 ;
F_4 ( V_14 -> V_29 ) ;
V_23 = F_2 ( V_12 , V_14 ) ;
V_24 = F_1 ( F_6 ( V_16 -> V_32 ) , 0 ) ;
for ( V_27 = 0 ; V_27 < V_14 -> V_30 ; V_27 ++ )
F_7 ( V_24 , V_23 ++ ) ;
F_8 ( V_23 - 1 ) ;
F_10 ( V_14 -> V_26 , V_14 -> V_30 ) ;
}
void F_11 ( struct V_11 * V_12 , struct V_13 * V_14 , int V_31 )
{
T_2 * V_23 , V_24 ;
int V_27 ;
if ( V_31 >= V_14 -> V_30 ) {
F_4 ( 1 ) ;
return;
}
V_14 -> V_31 = V_31 ;
if ( ! V_14 -> V_29 && ! V_14 -> V_33 )
return;
V_23 = F_2 ( V_12 , V_14 ) ;
for ( V_27 = V_14 -> V_31 ; V_27 < V_14 -> V_30 ; V_27 ++ ) {
V_24 = F_1 ( F_6 ( V_14 -> V_26 [ V_27 ] ) , 0 ) ;
F_7 ( V_24 , V_23 ++ ) ;
}
for ( V_27 = 0 ; V_27 < V_14 -> V_31 ; V_27 ++ ) {
V_24 = F_1 ( F_6 ( V_14 -> V_26 [ V_27 ] ) , 0 ) ;
F_7 ( V_24 , V_23 ++ ) ;
}
F_8 ( V_23 - 1 ) ;
}
static int F_12 ( struct V_13 * V_34 )
{
struct V_35 * V_35 ;
struct V_36 * V_37 ;
int V_27 ;
struct V_25 * V_38 ;
int V_26 = V_34 -> V_39 . V_40 / V_41 ;
F_4 ( V_34 -> V_26 ) ;
V_35 = V_34 -> V_39 . V_42 -> V_43 . V_44 -> V_45 ;
V_37 = V_35 -> V_46 ;
V_34 -> V_26 = F_13 ( V_26 * sizeof( struct V_25 * ) , V_47 ) ;
if ( V_34 -> V_26 == NULL )
return - V_48 ;
V_34 -> V_30 = V_26 ;
for ( V_27 = 0 ; V_27 < V_26 ; V_27 ++ ) {
V_38 = F_14 ( V_37 , V_27 ,
V_49 | V_47 ) ;
if ( F_15 ( V_38 ) )
goto V_50;
V_34 -> V_26 [ V_27 ] = V_38 ;
}
return 0 ;
V_50:
while ( V_27 -- )
F_16 ( V_34 -> V_26 [ V_27 ] ) ;
F_17 ( V_34 -> V_26 ) ;
V_34 -> V_26 = NULL ;
return F_18 ( V_38 ) ;
}
static void F_19 ( struct V_13 * V_34 )
{
int V_27 ;
for ( V_27 = 0 ; V_27 < V_34 -> V_30 ; V_27 ++ ) {
F_20 ( V_34 -> V_26 [ V_27 ] ) ;
F_16 ( V_34 -> V_26 [ V_27 ] ) ;
}
F_17 ( V_34 -> V_26 ) ;
V_34 -> V_26 = NULL ;
}
int F_21 ( struct V_13 * V_34 )
{
int V_51 = 0 ;
struct V_11 * V_12 = V_34 -> V_39 . V_12 ;
struct V_15 * V_16 = V_12 -> V_17 ;
F_22 ( & V_16 -> V_52 ) ;
if ( V_34 -> V_33 == 0 && V_34 -> V_29 == 0 ) {
V_51 = F_12 ( V_34 ) ;
if ( V_51 < 0 )
goto V_53;
V_51 = F_3 ( V_12 , V_34 ) ;
if ( V_51 < 0 ) {
F_19 ( V_34 ) ;
goto V_53;
}
}
V_34 -> V_33 ++ ;
V_53:
F_23 ( & V_16 -> V_52 ) ;
return V_51 ;
}
void F_24 ( struct V_13 * V_34 )
{
struct V_11 * V_12 = V_34 -> V_39 . V_12 ;
struct V_15 * V_16 = V_12 -> V_17 ;
F_22 ( & V_16 -> V_52 ) ;
F_4 ( ! V_34 -> V_33 ) ;
V_34 -> V_33 -- ;
if ( V_34 -> V_33 == 0 && V_34 -> V_29 == 0 ) {
F_9 ( V_12 , V_34 ) ;
F_19 ( V_34 ) ;
}
F_23 ( & V_16 -> V_52 ) ;
}
struct V_13 * F_25 ( struct V_11 * V_12 , int V_54 ,
const char * V_55 , int V_56 )
{
struct V_15 * V_16 = V_12 -> V_17 ;
struct V_13 * V_34 ;
struct V_19 * V_14 = V_16 -> V_21 ;
int V_51 ;
unsigned long V_20 , V_57 ;
if ( V_56 ) {
V_20 = V_14 -> V_20 ;
V_57 = V_14 -> V_20 + V_16 -> V_58 . V_59 - 1 ;
} else {
V_20 = V_14 -> V_20 + V_16 -> V_58 . V_59 ;
V_57 = V_14 -> V_57 ;
}
V_34 = F_26 ( sizeof( struct V_13 ) , V_47 ) ;
if ( V_34 == NULL )
return NULL ;
V_34 -> V_19 . V_55 = V_55 ;
V_34 -> V_29 = V_56 ;
V_34 -> V_33 = V_56 ;
V_34 -> V_31 = 0 ;
V_34 -> V_39 . V_12 = V_12 ;
V_51 = F_27 ( V_16 -> V_21 , & V_34 -> V_19 ,
V_54 , V_20 , V_57 , V_41 , NULL , NULL ) ;
if ( V_51 == 0 ) {
V_34 -> V_18 = V_34 -> V_19 . V_20 - V_14 -> V_20 ;
return V_34 ;
}
F_17 ( V_34 ) ;
return NULL ;
}
void F_28 ( struct V_11 * V_12 , struct V_13 * V_34 )
{
if ( V_34 -> V_60 ) {
F_24 ( V_34 ) ;
V_34 -> V_60 = 0 ;
}
F_4 ( V_34 -> V_33 && ! V_34 -> V_29 ) ;
F_29 ( & V_34 -> V_19 ) ;
F_17 ( V_34 ) ;
}
void F_30 ( struct V_11 * V_12 )
{
struct V_15 * V_16 = V_12 -> V_17 ;
F_31 ( & V_16 -> V_58 . V_61 ) ;
}
void F_32 ( struct V_11 * V_12 )
{
struct V_15 * V_16 = V_12 -> V_17 ;
if ( V_16 -> V_22 ) {
F_33 ( V_16 -> V_22 ) ;
V_16 -> V_22 = NULL ;
}
if ( V_16 -> V_62 ) {
F_34 ( V_12 -> V_63 , V_64 ,
V_16 -> V_65 ) ;
F_35 ( V_16 -> V_66 , V_67 ) ;
( void ) F_36 ( V_67 ) ;
}
if ( V_16 -> V_68 )
F_33 ( V_16 -> V_22 ) ;
}
int F_37 ( struct V_11 * V_12 , int V_69 )
{
struct V_15 * V_16 = V_12 -> V_17 ;
unsigned V_70 ;
unsigned long V_59 , V_71 ;
unsigned V_27 , V_72 ;
unsigned V_73 ;
T_1 V_74 ;
T_1 V_75 = 0 ;
struct V_76 * V_77 ;
int V_51 = 0 ;
T_1 V_24 ;
F_38 ( & V_16 -> V_52 ) ;
F_30 ( V_12 ) ;
V_77 = & V_16 -> V_58 ;
F_39 ( V_12 -> V_63 , V_64 , & V_16 -> V_65 ) ;
F_34 ( V_12 -> V_63 , V_64 ,
V_16 -> V_65 | V_78 ) ;
V_16 -> V_66 = F_36 ( V_67 ) ;
F_35 ( V_16 -> V_66 | V_79 , V_67 ) ;
( void ) F_36 ( V_67 ) ;
V_16 -> V_62 = 1 ;
V_77 -> V_80 = V_16 -> V_66 & V_81 ;
V_77 -> V_82 = 0xE0000000 ;
V_77 -> V_83 = F_40 ( V_12 -> V_63 , V_84 ) ;
V_70 = F_41 ( V_12 -> V_63 , V_84 )
>> V_10 ;
if ( V_77 -> V_83 == 0 || V_70 == 0 ) {
F_42 ( V_12 -> V_12 , L_1 ) ;
V_70 = 64 ;
V_77 -> V_83 = V_16 -> V_66 ;
}
V_77 -> V_85 = F_40 ( V_12 -> V_63 , V_86 ) ;
V_77 -> V_87 = F_41 ( V_12 -> V_63 , V_86 )
>> V_10 ;
V_16 -> V_21 = & V_12 -> V_63 -> V_19 [ V_86 ] ;
if ( V_77 -> V_87 == 0 || V_77 -> V_85 == 0 ) {
static struct V_19 V_88 ;
F_42 ( V_12 -> V_12 , L_2 ) ;
V_77 -> V_85 = 0x40000000 ;
V_77 -> V_87 = ( 128 * 1024 * 1024 ) >> V_10 ;
V_88 . V_20 = 0x40000000 ;
V_88 . V_57 = 0x40000000 + 128 * 1024 * 1024 - 1 ;
V_88 . V_55 = L_3 ;
V_88 . V_89 = V_90 ;
V_16 -> V_21 = & V_88 ;
}
F_43 ( V_12 -> V_63 , V_91 , & V_16 -> V_92 ) ;
V_71 = V_77 -> V_80 - V_16 -> V_92
- V_41 ;
V_59 = V_71 ;
F_44 ( V_93 L_4 ) ;
F_44 ( V_93 L_5 , V_16 -> V_92 ) ;
F_44 ( V_93 L_6 ,
V_71 / 1024 ) ;
V_75 = ( V_16 -> V_65 >> 4 ) & 0x7 ;
F_44 ( V_93 L_7 ,
( V_75 == 1 ) ? 1 : ( 2 << ( V_75 - 1 ) ) , V_75 ) ;
if ( V_69 && ( V_70 != V_77 -> V_70 ) &&
( V_59 != V_77 -> V_59 ) ) {
F_42 ( V_12 -> V_12 , L_8 ) ;
V_51 = - V_28 ;
goto V_94;
}
V_77 -> V_70 = V_70 ;
V_77 -> V_59 = V_59 ;
V_16 -> V_71 = V_71 ;
V_16 -> V_22 = F_45 ( V_77 -> V_80 ,
V_70 << V_10 ) ;
if ( ! V_16 -> V_22 ) {
F_42 ( V_12 -> V_12 , L_9 ) ;
V_51 = - V_48 ;
goto V_94;
}
V_16 -> V_68 = F_46 ( V_16 -> V_92 , V_59 ) ;
if ( ! V_16 -> V_68 ) {
F_42 ( V_12 -> V_12 , L_10 ) ;
V_51 = - V_48 ;
goto V_94;
}
V_73 = V_16 -> V_92 >> V_10 ;
V_74 = V_72 = V_71 >> V_10 ;
F_44 ( V_93 L_11 ,
V_72 , V_73 << V_10 , 0 ) ;
for ( V_27 = 0 ; V_27 < V_72 ; ++ V_27 ) {
V_24 = F_1 ( V_73 + V_27 , 0 ) ;
F_7 ( V_24 , V_16 -> V_22 + V_27 ) ;
}
V_73 = F_6 ( V_16 -> V_32 ) ;
V_24 = F_1 ( V_73 , 0 ) ;
for (; V_27 < V_70 ; ++ V_27 )
F_7 ( V_24 , V_16 -> V_22 + V_27 ) ;
( void ) F_8 ( V_16 -> V_22 + V_27 - 1 ) ;
return 0 ;
V_94:
F_32 ( V_12 ) ;
return V_51 ;
}
