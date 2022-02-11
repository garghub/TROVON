void F_1 ( int V_1 )
{
if ( V_1 < 0 )
return;
V_2 = V_1 ;
}
static struct V_3 * F_2 ( struct V_4 * V_5 , int type )
{
struct V_3 * V_6 ;
T_1 V_7 ;
V_7 = sizeof( struct V_3 ) ;
if ( V_2 ) {
V_7 = F_3 ( V_7 , F_4 () ) ;
V_7 += V_2 ;
}
V_6 = F_5 ( V_7 , V_8 ) ;
if ( ! V_6 ) return NULL ;
V_6 -> type = type ;
V_6 -> V_5 = V_5 ;
F_6 ( & V_6 -> V_9 ) ;
F_6 ( & V_6 -> V_10 ) ;
F_6 ( & V_6 -> V_11 ) ;
V_6 -> V_12 = ( void * ) V_6 + F_3 ( sizeof( struct V_3 ) ,
F_4 () ) ;
return V_6 ;
}
int F_7 ( struct V_4 * V_5 )
{
struct V_3 * V_6 ;
V_6 = F_2 ( V_5 , V_13 ) ;
if ( ! V_6 ) {
F_8 ( L_1 , V_14 ) ;
return - V_15 ;
}
F_9 ( & V_6 -> V_10 , & V_16 ) ;
F_10 ( L_2 , V_5 -> V_17 ) ;
return 0 ;
}
struct V_3 * F_11 ( struct V_4 * V_5 )
{
struct V_3 * V_6 ;
F_12 (pe, &eeh_phb_pe, child) {
if ( ( V_6 -> type & V_13 ) && V_6 -> V_5 == V_5 )
return V_6 ;
}
return NULL ;
}
static struct V_3 * F_13 ( struct V_3 * V_6 ,
struct V_3 * V_18 )
{
struct V_19 * V_20 = V_6 -> V_9 . V_20 ;
if ( V_20 == & V_6 -> V_9 ) {
while ( 1 ) {
if ( V_6 == V_18 )
return NULL ;
V_20 = V_6 -> V_10 . V_20 ;
if ( V_20 != & V_6 -> V_21 -> V_9 )
break;
V_6 = V_6 -> V_21 ;
}
}
return F_14 ( V_20 , struct V_3 , V_10 ) ;
}
void * F_15 ( struct V_3 * V_18 ,
T_2 V_22 , void * V_23 )
{
struct V_3 * V_6 ;
void * V_24 ;
for ( V_6 = V_18 ; V_6 ; V_6 = F_13 ( V_6 , V_18 ) ) {
V_24 = V_22 ( V_6 , V_23 ) ;
if ( V_24 ) return V_24 ;
}
return NULL ;
}
void * F_16 ( struct V_3 * V_18 ,
T_2 V_22 , void * V_23 )
{
struct V_3 * V_6 ;
struct V_25 * V_26 , * V_27 ;
void * V_24 ;
if ( ! V_18 ) {
F_17 ( L_3 ,
V_14 , V_18 ) ;
return NULL ;
}
for ( V_6 = V_18 ; V_6 ; V_6 = F_13 ( V_6 , V_18 ) ) {
F_18 (pe, edev, tmp) {
V_24 = V_22 ( V_26 , V_23 ) ;
if ( V_24 )
return V_24 ;
}
}
return NULL ;
}
static void * F_19 ( void * V_12 , void * V_23 )
{
struct V_3 * V_6 = (struct V_3 * ) V_12 ;
struct V_25 * V_26 = (struct V_25 * ) V_23 ;
if ( V_6 -> type & V_13 )
return NULL ;
if ( F_20 ( V_28 ) ) {
if ( V_26 -> V_29 == V_6 -> V_30 )
return V_6 ;
} else {
if ( V_26 -> V_29 &&
( V_26 -> V_29 == V_6 -> V_30 ) )
return V_6 ;
}
if ( V_26 -> V_31 &&
( V_26 -> V_31 == V_6 -> V_31 ) )
return V_6 ;
return NULL ;
}
struct V_3 * F_21 ( struct V_25 * V_26 )
{
struct V_3 * V_18 = F_11 ( V_26 -> V_5 ) ;
struct V_3 * V_6 ;
V_6 = F_15 ( V_18 , F_19 , V_26 ) ;
return V_6 ;
}
static struct V_3 * F_22 ( struct V_25 * V_26 )
{
struct V_25 * V_21 ;
struct V_32 * V_33 = F_23 ( V_26 ) ;
V_33 = V_33 ? V_33 -> V_21 : NULL ;
while ( V_33 ) {
V_21 = F_24 ( V_33 ) ;
if ( ! V_21 )
return NULL ;
if ( V_21 -> V_6 )
return V_21 -> V_6 ;
V_33 = V_33 -> V_21 ;
}
return NULL ;
}
int F_25 ( struct V_25 * V_26 )
{
struct V_3 * V_6 , * V_21 ;
if ( ! F_20 ( V_28 ) && ! V_26 -> V_29 ) {
F_8 ( L_4 ,
V_14 , V_26 -> V_31 , V_26 -> V_5 -> V_17 ) ;
return - V_34 ;
}
V_6 = F_21 ( V_26 ) ;
if ( V_6 && ! ( V_6 -> type & V_35 ) ) {
V_6 -> type = V_36 ;
V_26 -> V_6 = V_6 ;
F_9 ( & V_26 -> V_37 , & V_6 -> V_11 ) ;
F_10 ( L_5 ,
V_26 -> V_5 -> V_17 ,
V_26 -> V_31 >> 8 ,
F_26 ( V_26 -> V_31 & 0xFF ) ,
F_27 ( V_26 -> V_31 & 0xFF ) ,
V_6 -> V_30 ) ;
return 0 ;
} else if ( V_6 && ( V_6 -> type & V_35 ) ) {
F_9 ( & V_26 -> V_37 , & V_6 -> V_11 ) ;
V_26 -> V_6 = V_6 ;
V_21 = V_6 ;
while ( V_21 ) {
if ( ! ( V_21 -> type & V_35 ) )
break;
V_21 -> type &= ~ ( V_35 | V_38 ) ;
V_21 = V_21 -> V_21 ;
}
F_10 ( L_6
L_7 ,
V_26 -> V_5 -> V_17 ,
V_26 -> V_31 >> 8 ,
F_26 ( V_26 -> V_31 & 0xFF ) ,
F_27 ( V_26 -> V_31 & 0xFF ) ,
V_6 -> V_30 , V_6 -> V_21 -> V_30 ) ;
return 0 ;
}
V_6 = F_2 ( V_26 -> V_5 , V_39 ) ;
if ( ! V_6 ) {
F_8 ( L_1 , V_14 ) ;
return - V_15 ;
}
V_6 -> V_30 = V_26 -> V_29 ;
V_6 -> V_31 = V_26 -> V_31 ;
V_21 = F_22 ( V_26 ) ;
if ( ! V_21 ) {
V_21 = F_11 ( V_26 -> V_5 ) ;
if ( ! V_21 ) {
F_8 ( L_8 ,
V_14 , V_26 -> V_5 -> V_17 ) ;
V_26 -> V_6 = NULL ;
F_28 ( V_6 ) ;
return - V_40 ;
}
}
V_6 -> V_21 = V_21 ;
F_9 ( & V_6 -> V_10 , & V_21 -> V_9 ) ;
F_9 ( & V_26 -> V_37 , & V_6 -> V_11 ) ;
V_26 -> V_6 = V_6 ;
F_10 ( L_9
L_10 ,
V_26 -> V_5 -> V_17 ,
V_26 -> V_31 >> 8 ,
F_26 ( V_26 -> V_31 & 0xFF ) ,
F_27 ( V_26 -> V_31 & 0xFF ) ,
V_6 -> V_30 , V_6 -> V_21 -> V_30 ) ;
return 0 ;
}
int F_29 ( struct V_25 * V_26 )
{
struct V_3 * V_6 , * V_21 , * V_10 ;
int V_41 ;
if ( ! V_26 -> V_6 ) {
F_10 ( L_11 ,
V_14 , V_26 -> V_5 -> V_17 ,
V_26 -> V_31 >> 8 ,
F_26 ( V_26 -> V_31 & 0xFF ) ,
F_27 ( V_26 -> V_31 & 0xFF ) ) ;
return - V_40 ;
}
V_6 = F_30 ( V_26 ) ;
V_26 -> V_6 = NULL ;
F_31 ( & V_26 -> V_37 ) ;
while ( 1 ) {
V_21 = V_6 -> V_21 ;
if ( V_6 -> type & V_13 )
break;
if ( ! ( V_6 -> V_42 & V_38 ) ) {
if ( F_32 ( & V_6 -> V_11 ) &&
F_32 ( & V_6 -> V_9 ) ) {
F_31 ( & V_6 -> V_10 ) ;
F_28 ( V_6 ) ;
} else {
break;
}
} else {
if ( F_32 ( & V_6 -> V_11 ) ) {
V_41 = 0 ;
F_12 (child, &pe->child_list, child) {
if ( ! ( V_10 -> type & V_35 ) ) {
V_41 ++ ;
break;
}
}
if ( ! V_41 )
V_6 -> type |= V_35 ;
else
break;
}
}
V_6 = V_21 ;
}
return 0 ;
}
void F_33 ( struct V_3 * V_6 )
{
struct V_43 V_44 ;
if ( ! V_6 ) return;
if ( V_6 -> V_45 <= 0 ) {
V_6 -> V_45 = 0 ;
F_34 ( & V_6 -> V_44 ) ;
} else {
F_34 ( & V_44 ) ;
if ( V_44 . V_46 - V_6 -> V_44 . V_46 > 3600 ) {
V_6 -> V_44 = V_44 ;
V_6 -> V_45 = 0 ;
}
}
}
static void * F_35 ( void * V_12 , void * V_23 )
{
struct V_3 * V_6 = (struct V_3 * ) V_12 ;
int V_42 = * ( ( int * ) V_23 ) ;
struct V_25 * V_26 , * V_27 ;
struct V_47 * V_48 ;
if ( V_6 -> V_42 & V_49 )
return NULL ;
V_6 -> V_42 |= V_42 ;
if ( ! ( V_42 & V_50 ) )
return NULL ;
F_18 (pe, edev, tmp) {
V_48 = F_36 ( V_26 ) ;
if ( V_48 )
V_48 -> V_51 = V_52 ;
}
if ( V_6 -> V_42 & V_53 )
V_6 -> V_42 |= V_54 ;
return NULL ;
}
void F_37 ( struct V_3 * V_6 , int V_42 )
{
F_15 ( V_6 , F_35 , & V_42 ) ;
}
static void * F_38 ( void * V_12 , void * V_23 )
{
struct V_25 * V_26 = V_12 ;
int V_55 = * ( ( int * ) V_23 ) ;
V_26 -> V_55 |= V_55 ;
return NULL ;
}
void F_39 ( struct V_3 * V_6 , int V_55 )
{
F_16 ( V_6 , F_38 , & V_55 ) ;
}
static void * F_40 ( void * V_12 , void * V_23 )
{
struct V_3 * V_6 = (struct V_3 * ) V_12 ;
int V_42 = * ( ( int * ) V_23 ) ;
struct V_25 * V_26 , * V_27 ;
struct V_47 * V_48 ;
if ( V_6 -> V_42 & V_49 )
return NULL ;
V_6 -> V_42 &= ~ V_42 ;
if ( ! ( V_42 & V_50 ) )
return NULL ;
V_6 -> V_56 = 0 ;
F_18 (pe, edev, tmp) {
V_48 = F_36 ( V_26 ) ;
if ( ! V_48 )
continue;
V_48 -> V_51 = V_57 ;
}
if ( V_6 -> V_42 & V_53 )
V_6 -> V_42 &= ~ V_54 ;
return NULL ;
}
void F_41 ( struct V_3 * V_6 , int V_42 )
{
F_15 ( V_6 , F_40 , & V_42 ) ;
}
static void F_42 ( struct V_25 * V_26 )
{
struct V_32 * V_33 = F_23 ( V_26 ) ;
int V_58 ;
T_3 V_59 ;
int V_60 = 0 ;
if ( ! ( V_26 -> V_55 & ( V_61 | V_62 ) ) )
return;
F_10 ( L_12 ,
V_14 , V_26 -> V_5 -> V_17 ,
V_26 -> V_31 >> 8 ,
F_26 ( V_26 -> V_31 & 0xFF ) ,
F_27 ( V_26 -> V_31 & 0xFF ) ) ;
V_58 = V_26 -> V_63 ;
V_64 -> V_65 ( V_33 , V_58 + V_66 , 2 , & V_59 ) ;
if ( ! ( V_59 & V_67 ) ) {
F_10 ( L_13 , V_59 ) ;
return;
}
V_64 -> V_65 ( V_33 , V_58 + V_68 , 2 , & V_59 ) ;
if ( V_59 & V_69 ) {
V_64 -> V_65 ( V_33 , V_58 + V_70 , 2 , & V_59 ) ;
if ( V_59 & V_71 ) {
F_10 ( L_14 ) ;
V_59 &= ~ ( V_71 | V_72 ) ;
V_59 |= ( 0x0100 & V_72 ) ;
V_64 -> V_73 ( V_33 , V_58 + V_70 , 2 , V_59 ) ;
F_43 ( 2 * 1000 ) ;
}
}
V_64 -> V_65 ( V_33 , V_58 + V_74 , 2 , & V_59 ) ;
V_59 &= ~ V_75 ;
V_64 -> V_73 ( V_33 , V_58 + V_74 , 2 , V_59 ) ;
V_64 -> V_65 ( V_33 , V_58 + V_76 , 4 , & V_59 ) ;
if ( ! ( V_59 & V_77 ) ) {
F_10 ( L_15 , V_59 ) ;
F_43 ( 1000 ) ;
return;
}
V_60 = 0 ;
while ( V_60 < 5000 ) {
F_43 ( 20 ) ;
V_60 += 20 ;
V_64 -> V_65 ( V_33 , V_58 + V_78 , 2 , & V_59 ) ;
if ( V_59 & V_79 )
break;
}
if ( V_59 & V_79 )
F_10 ( L_16 ,
( V_59 & V_80 ) ? L_17 : L_18 ) ;
else
F_10 ( L_19 , V_59 ) ;
}
static void F_44 ( struct V_25 * V_26 )
{
struct V_32 * V_33 = F_23 ( V_26 ) ;
int V_81 ;
for ( V_81 = 4 ; V_81 < 13 ; V_81 ++ )
V_64 -> V_73 ( V_33 , V_81 * 4 , 4 , V_26 -> V_82 [ V_81 ] ) ;
V_64 -> V_73 ( V_33 , 14 * 4 , 4 , V_26 -> V_82 [ 14 ] ) ;
V_64 -> V_73 ( V_33 , V_83 , 1 ,
F_45 ( V_83 ) ) ;
V_64 -> V_73 ( V_33 , V_84 , 1 ,
F_45 ( V_84 ) ) ;
V_64 -> V_73 ( V_33 , 15 * 4 , 4 , V_26 -> V_82 [ 15 ] ) ;
V_64 -> V_73 ( V_33 , V_85 , 4 , V_26 -> V_82 [ 1 ] ) ;
F_42 ( V_26 ) ;
}
static void F_46 ( struct V_25 * V_26 )
{
struct V_32 * V_33 = F_23 ( V_26 ) ;
int V_81 ;
T_4 V_86 ;
for ( V_81 = 4 ; V_81 < 10 ; V_81 ++ )
V_64 -> V_73 ( V_33 , V_81 * 4 , 4 , V_26 -> V_82 [ V_81 ] ) ;
V_64 -> V_73 ( V_33 , 12 * 4 , 4 , V_26 -> V_82 [ 12 ] ) ;
V_64 -> V_73 ( V_33 , V_83 , 1 ,
F_45 ( V_83 ) ) ;
V_64 -> V_73 ( V_33 , V_84 , 1 ,
F_45 ( V_84 ) ) ;
V_64 -> V_73 ( V_33 , 15 * 4 , 4 , V_26 -> V_82 [ 15 ] ) ;
V_64 -> V_65 ( V_33 , V_85 , 4 , & V_86 ) ;
if ( V_26 -> V_82 [ 1 ] & V_87 )
V_86 |= V_87 ;
else
V_86 &= ~ V_87 ;
if ( V_26 -> V_82 [ 1 ] & V_88 )
V_86 |= V_88 ;
else
V_86 &= ~ V_88 ;
V_64 -> V_73 ( V_33 , V_85 , 4 , V_86 ) ;
}
static void * F_47 ( void * V_12 , void * V_23 )
{
struct V_25 * V_26 = (struct V_25 * ) V_12 ;
struct V_32 * V_33 = F_23 ( V_26 ) ;
if ( V_26 -> V_55 & V_89 )
F_44 ( V_26 ) ;
else
F_46 ( V_26 ) ;
if ( V_64 -> V_90 && V_33 )
V_64 -> V_90 ( V_33 ) ;
return NULL ;
}
void F_48 ( struct V_3 * V_6 )
{
F_16 ( V_6 , F_47 , NULL ) ;
}
const char * F_49 ( struct V_3 * V_6 )
{
struct V_91 * V_92 = F_50 ( V_6 ) ;
struct V_93 * V_94 = F_51 ( V_92 ) ;
const char * V_95 = NULL ;
if ( ! V_94 )
goto V_96;
if ( F_52 ( V_92 ) ) {
V_95 = F_53 ( V_94 , L_20 , NULL ) ;
if ( ! V_95 )
V_95 = F_53 ( V_94 , L_21 , NULL ) ;
if ( V_95 )
goto V_96;
V_94 = V_94 -> V_10 ;
if ( ! V_94 )
goto V_96;
}
V_95 = F_53 ( V_94 , L_20 , NULL ) ;
if ( ! V_95 )
V_95 = F_53 ( V_94 , L_22 , NULL ) ;
V_96:
return V_95 ? V_95 : L_23 ;
}
struct V_91 * F_50 ( struct V_3 * V_6 )
{
struct V_91 * V_92 = NULL ;
struct V_25 * V_26 ;
struct V_47 * V_48 ;
if ( V_6 -> type & V_13 ) {
V_92 = V_6 -> V_5 -> V_92 ;
} else if ( V_6 -> type & V_36 ||
V_6 -> type & V_39 ) {
if ( V_6 -> V_92 ) {
V_92 = V_6 -> V_92 ;
goto V_96;
}
V_26 = F_54 ( & V_6 -> V_11 , struct V_25 , V_37 ) ;
V_48 = F_36 ( V_26 ) ;
if ( V_48 )
V_92 = V_48 -> V_92 ;
}
V_96:
return V_92 ;
}
