static inline T_1 F_1 ( T_1 V_1 , int type )
{
T_1 V_2 = V_3 ;
F_2 ( V_1 & ~ ( 0xFFFFFFFF >> V_4 ) ) ;
if ( type & V_5 )
V_2 |= V_6 ;
if ( type & V_7 )
V_2 |= V_8 ;
if ( type & V_9 )
V_2 |= V_10 ;
return ( V_1 << V_4 ) | V_2 ;
}
static T_2 T_3 * F_3 ( struct V_11 * V_12 , struct V_13 * V_14 )
{
struct V_15 * V_16 = V_12 -> V_17 ;
unsigned long V_18 ;
V_18 = V_14 -> V_19 . V_20 - V_16 -> V_21 -> V_20 ;
return V_16 -> V_22 + ( V_18 >> V_4 ) ;
}
static int F_4 ( struct V_11 * V_12 , struct V_13 * V_14 ,
int V_23 )
{
T_2 T_3 * V_24 ;
T_2 V_25 ;
struct V_26 * * V_27 ;
int V_28 ;
if ( V_14 -> V_27 == NULL ) {
F_5 ( 1 ) ;
return - V_29 ;
}
F_5 ( V_14 -> V_30 ) ;
V_24 = F_3 ( V_12 , V_14 ) ;
V_27 = V_14 -> V_27 ;
if ( ! V_23 ) {
F_6 ( V_27 , V_14 -> V_31 ) ;
}
for ( V_28 = V_14 -> V_32 ; V_28 < V_14 -> V_31 ; V_28 ++ ) {
V_25 = F_1 ( F_7 ( V_14 -> V_27 [ V_28 ] ) , 0 ) ;
F_8 ( V_25 , V_24 ++ ) ;
}
for ( V_28 = 0 ; V_28 < V_14 -> V_32 ; V_28 ++ ) {
V_25 = F_1 ( F_7 ( V_14 -> V_27 [ V_28 ] ) , 0 ) ;
F_8 ( V_25 , V_24 ++ ) ;
}
F_9 ( V_24 - 1 ) ;
return 0 ;
}
static void F_10 ( struct V_11 * V_12 , struct V_13 * V_14 )
{
struct V_15 * V_16 = V_12 -> V_17 ;
T_2 T_3 * V_24 ;
T_2 V_25 ;
int V_28 ;
F_5 ( V_14 -> V_30 ) ;
V_24 = F_3 ( V_12 , V_14 ) ;
V_25 = F_1 ( F_7 ( V_16 -> V_33 ) , 0 ) ;
for ( V_28 = 0 ; V_28 < V_14 -> V_31 ; V_28 ++ )
F_8 ( V_25 , V_24 ++ ) ;
F_9 ( V_24 - 1 ) ;
F_11 ( V_14 -> V_27 , V_14 -> V_31 ) ;
}
void F_12 ( struct V_11 * V_12 , struct V_13 * V_14 , int V_32 )
{
T_2 T_3 * V_24 ;
T_2 V_25 ;
int V_28 ;
if ( V_32 >= V_14 -> V_31 ) {
F_5 ( 1 ) ;
return;
}
V_14 -> V_32 = V_32 ;
if ( ! V_14 -> V_30 && ! V_14 -> V_34 )
return;
V_24 = F_3 ( V_12 , V_14 ) ;
for ( V_28 = V_14 -> V_32 ; V_28 < V_14 -> V_31 ; V_28 ++ ) {
V_25 = F_1 ( F_7 ( V_14 -> V_27 [ V_28 ] ) , 0 ) ;
F_8 ( V_25 , V_24 ++ ) ;
}
for ( V_28 = 0 ; V_28 < V_14 -> V_32 ; V_28 ++ ) {
V_25 = F_1 ( F_7 ( V_14 -> V_27 [ V_28 ] ) , 0 ) ;
F_8 ( V_25 , V_24 ++ ) ;
}
F_9 ( V_24 - 1 ) ;
}
static int F_13 ( struct V_13 * V_35 )
{
struct V_36 * V_36 ;
struct V_37 * V_38 ;
int V_28 ;
struct V_26 * V_39 ;
int V_27 = V_35 -> V_40 . V_41 / V_42 ;
F_5 ( V_35 -> V_27 ) ;
V_36 = F_14 ( V_35 -> V_40 . V_43 ) ;
V_38 = V_36 -> V_44 ;
V_35 -> V_27 = F_15 ( V_27 * sizeof( struct V_26 * ) , V_45 ) ;
if ( V_35 -> V_27 == NULL )
return - V_46 ;
V_35 -> V_31 = V_27 ;
for ( V_28 = 0 ; V_28 < V_27 ; V_28 ++ ) {
V_39 = F_16 ( V_38 , V_28 ) ;
if ( F_17 ( V_39 ) )
goto V_47;
V_35 -> V_27 [ V_28 ] = V_39 ;
}
return 0 ;
V_47:
while ( V_28 -- )
F_18 ( V_35 -> V_27 [ V_28 ] ) ;
F_19 ( V_35 -> V_27 ) ;
V_35 -> V_27 = NULL ;
return F_20 ( V_39 ) ;
}
static void F_21 ( struct V_13 * V_35 )
{
int V_28 ;
for ( V_28 = 0 ; V_28 < V_35 -> V_31 ; V_28 ++ ) {
F_22 ( V_35 -> V_27 [ V_28 ] ) ;
F_18 ( V_35 -> V_27 [ V_28 ] ) ;
}
F_19 ( V_35 -> V_27 ) ;
V_35 -> V_27 = NULL ;
}
int F_23 ( struct V_13 * V_35 )
{
int V_48 = 0 ;
struct V_11 * V_12 = V_35 -> V_40 . V_12 ;
struct V_15 * V_16 = V_12 -> V_17 ;
F_24 ( & V_16 -> V_49 ) ;
if ( V_35 -> V_34 == 0 && V_35 -> V_30 == 0 ) {
V_48 = F_13 ( V_35 ) ;
if ( V_48 < 0 )
goto V_50;
V_48 = F_4 ( V_12 , V_35 , 0 ) ;
if ( V_48 < 0 ) {
F_21 ( V_35 ) ;
goto V_50;
}
}
V_35 -> V_34 ++ ;
V_50:
F_25 ( & V_16 -> V_49 ) ;
return V_48 ;
}
void F_26 ( struct V_13 * V_35 )
{
struct V_11 * V_12 = V_35 -> V_40 . V_12 ;
struct V_15 * V_16 = V_12 -> V_17 ;
F_24 ( & V_16 -> V_49 ) ;
F_5 ( ! V_35 -> V_34 ) ;
V_35 -> V_34 -- ;
if ( V_35 -> V_34 == 0 && V_35 -> V_30 == 0 ) {
F_10 ( V_12 , V_35 ) ;
F_21 ( V_35 ) ;
}
F_25 ( & V_16 -> V_49 ) ;
}
struct V_13 * F_27 ( struct V_11 * V_12 , int V_51 ,
const char * V_52 , int V_53 )
{
struct V_15 * V_16 = V_12 -> V_17 ;
struct V_13 * V_35 ;
struct V_19 * V_14 = V_16 -> V_21 ;
int V_48 ;
unsigned long V_20 , V_54 ;
if ( V_53 ) {
V_20 = V_14 -> V_20 ;
V_54 = V_14 -> V_20 + V_16 -> V_55 . V_56 - 1 ;
} else {
V_20 = V_14 -> V_20 + V_16 -> V_55 . V_56 ;
V_54 = V_14 -> V_54 ;
}
V_35 = F_28 ( sizeof( struct V_13 ) , V_45 ) ;
if ( V_35 == NULL )
return NULL ;
V_35 -> V_19 . V_52 = V_52 ;
V_35 -> V_30 = V_53 ;
V_35 -> V_34 = V_53 ;
V_35 -> V_32 = 0 ;
V_35 -> V_40 . V_12 = V_12 ;
V_48 = F_29 ( V_16 -> V_21 , & V_35 -> V_19 ,
V_51 , V_20 , V_54 , V_42 , NULL , NULL ) ;
if ( V_48 == 0 ) {
V_35 -> V_18 = V_35 -> V_19 . V_20 - V_14 -> V_20 ;
return V_35 ;
}
F_19 ( V_35 ) ;
return NULL ;
}
void F_30 ( struct V_11 * V_12 , struct V_13 * V_35 )
{
if ( V_35 -> V_57 ) {
F_26 ( V_35 ) ;
V_35 -> V_57 = 0 ;
}
F_5 ( V_35 -> V_34 && ! V_35 -> V_30 ) ;
F_31 ( & V_35 -> V_19 ) ;
F_19 ( V_35 ) ;
}
static void F_32 ( struct V_11 * V_12 )
{
struct V_15 * V_16 = V_12 -> V_17 ;
F_33 ( & V_16 -> V_55 . V_58 ) ;
}
void F_34 ( struct V_11 * V_12 )
{
struct V_15 * V_16 = V_12 -> V_17 ;
if ( V_16 -> V_22 ) {
F_35 ( V_16 -> V_22 ) ;
V_16 -> V_22 = NULL ;
}
if ( V_16 -> V_59 ) {
F_36 ( V_12 -> V_60 , V_61 ,
V_16 -> V_62 ) ;
F_37 ( V_16 -> V_63 , V_64 ) ;
( void ) F_38 ( V_64 ) ;
}
if ( V_16 -> V_65 )
F_35 ( V_16 -> V_22 ) ;
}
int F_39 ( struct V_11 * V_12 , int V_23 )
{
struct V_15 * V_16 = V_12 -> V_17 ;
unsigned V_66 ;
unsigned long V_56 , V_67 ;
unsigned V_28 , V_68 ;
unsigned V_69 ;
struct V_70 * V_71 ;
int V_48 = 0 ;
T_1 V_25 ;
if ( ! V_23 ) {
F_40 ( & V_16 -> V_49 ) ;
F_32 ( V_12 ) ;
}
V_71 = & V_16 -> V_55 ;
F_41 ( V_12 -> V_60 , V_61 , & V_16 -> V_62 ) ;
F_36 ( V_12 -> V_60 , V_61 ,
V_16 -> V_62 | V_72 ) ;
V_16 -> V_63 = F_38 ( V_64 ) ;
F_37 ( V_16 -> V_63 | V_73 , V_64 ) ;
( void ) F_38 ( V_64 ) ;
V_16 -> V_59 = 1 ;
V_71 -> V_74 = V_16 -> V_63 & V_75 ;
V_71 -> V_76 = 0xE0000000 ;
V_71 -> V_77 = F_42 ( V_12 -> V_60 , V_78 ) ;
V_66 = F_43 ( V_12 -> V_60 , V_78 )
>> V_4 ;
if ( V_71 -> V_77 == 0 || V_66 == 0 ) {
F_44 ( V_12 -> V_12 , L_1 ) ;
V_66 = 64 ;
V_71 -> V_77 = V_16 -> V_63 ;
}
V_71 -> V_79 = F_42 ( V_12 -> V_60 , V_80 ) ;
V_71 -> V_81 = F_43 ( V_12 -> V_60 , V_80 )
>> V_4 ;
V_16 -> V_21 = & V_12 -> V_60 -> V_19 [ V_80 ] ;
if ( V_71 -> V_81 == 0 || V_71 -> V_79 == 0 ) {
static struct V_19 V_82 ;
F_44 ( V_12 -> V_12 , L_2 ) ;
V_71 -> V_79 = 0x40000000 ;
V_71 -> V_81 = ( 128 * 1024 * 1024 ) >> V_4 ;
V_82 . V_20 = 0x40000000 ;
V_82 . V_54 = 0x40000000 + 128 * 1024 * 1024 - 1 ;
V_82 . V_52 = L_3 ;
V_82 . V_83 = V_84 ;
V_16 -> V_21 = & V_82 ;
}
F_45 ( V_12 -> V_60 , V_85 , & V_16 -> V_86 ) ;
V_67 = V_71 -> V_74 - V_16 -> V_86
- V_42 ;
V_56 = V_67 ;
F_44 ( V_12 -> V_12 , L_4 ,
V_16 -> V_86 , V_67 / 1024 ) ;
if ( V_23 && ( V_66 != V_71 -> V_66 ) &&
( V_56 != V_71 -> V_56 ) ) {
F_46 ( V_12 -> V_12 , L_5 ) ;
V_48 = - V_29 ;
goto V_87;
}
V_71 -> V_66 = V_66 ;
V_71 -> V_56 = V_56 ;
V_16 -> V_67 = V_67 ;
if ( ! V_23 )
V_16 -> V_22 = F_47 ( V_71 -> V_74 ,
V_66 << V_4 ) ;
if ( ! V_16 -> V_22 ) {
F_46 ( V_12 -> V_12 , L_6 ) ;
V_48 = - V_46 ;
goto V_87;
}
if ( ! V_23 )
V_16 -> V_65 = F_48 ( V_16 -> V_86 ,
V_56 ) ;
if ( ! V_16 -> V_65 ) {
F_46 ( V_12 -> V_12 , L_7 ) ;
V_48 = - V_46 ;
goto V_87;
}
V_69 = V_16 -> V_86 >> V_4 ;
V_68 = V_67 >> V_4 ;
F_44 ( V_12 -> V_12 , L_8 ,
V_68 , V_69 << V_4 , 0 ) ;
for ( V_28 = 0 ; V_28 < V_68 ; ++ V_28 ) {
V_25 = F_1 ( V_69 + V_28 , 0 ) ;
F_8 ( V_25 , V_16 -> V_22 + V_28 ) ;
}
V_69 = F_7 ( V_16 -> V_33 ) ;
V_25 = F_1 ( V_69 , 0 ) ;
for (; V_28 < V_66 ; ++ V_28 )
F_8 ( V_25 , V_16 -> V_22 + V_28 ) ;
( void ) F_9 ( V_16 -> V_22 + V_28 - 1 ) ;
return 0 ;
V_87:
F_34 ( V_12 ) ;
return V_48 ;
}
int F_49 ( struct V_11 * V_12 )
{
struct V_15 * V_16 = V_12 -> V_17 ;
struct V_19 * V_14 = V_16 -> V_21 -> V_88 ;
struct V_13 * V_89 ;
unsigned int V_90 = 0 , V_91 = 0 , V_41 = 0 ;
F_24 ( & V_16 -> V_49 ) ;
F_39 ( V_12 , 1 ) ;
while ( V_14 != NULL ) {
V_89 = F_50 ( V_14 , struct V_13 , V_19 ) ;
if ( V_89 -> V_27 ) {
F_4 ( V_12 , V_89 , 1 ) ;
V_41 += V_89 -> V_19 . V_54 - V_89 -> V_19 . V_20 ;
V_90 ++ ;
}
V_14 = V_14 -> V_92 ;
V_91 ++ ;
}
F_25 ( & V_16 -> V_49 ) ;
F_51 ( L_9 , V_90 ,
V_91 , ( V_41 / 1024 ) ) ;
return 0 ;
}
