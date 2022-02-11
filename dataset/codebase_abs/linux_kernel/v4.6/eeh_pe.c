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
if ( V_26 -> V_34 )
V_33 = F_24 ( V_26 -> V_34 ) ;
else
V_33 = V_33 ? V_33 -> V_21 : NULL ;
while ( V_33 ) {
V_21 = F_25 ( V_33 ) ;
if ( ! V_21 )
return NULL ;
if ( V_21 -> V_6 )
return V_21 -> V_6 ;
V_33 = V_33 -> V_21 ;
}
return NULL ;
}
int F_26 ( struct V_25 * V_26 )
{
struct V_3 * V_6 , * V_21 ;
if ( ! F_20 ( V_28 ) && ! V_26 -> V_29 ) {
F_8 ( L_4 ,
V_14 , V_26 -> V_31 , V_26 -> V_5 -> V_17 ) ;
return - V_35 ;
}
V_6 = F_21 ( V_26 ) ;
if ( V_6 && ! ( V_6 -> type & V_36 ) ) {
V_6 -> type = V_37 ;
V_26 -> V_6 = V_6 ;
F_9 ( & V_26 -> V_38 , & V_6 -> V_11 ) ;
F_10 ( L_5 ,
V_26 -> V_5 -> V_17 ,
V_26 -> V_31 >> 8 ,
F_27 ( V_26 -> V_31 & 0xFF ) ,
F_28 ( V_26 -> V_31 & 0xFF ) ,
V_6 -> V_30 ) ;
return 0 ;
} else if ( V_6 && ( V_6 -> type & V_36 ) ) {
F_9 ( & V_26 -> V_38 , & V_6 -> V_11 ) ;
V_26 -> V_6 = V_6 ;
V_21 = V_6 ;
while ( V_21 ) {
if ( ! ( V_21 -> type & V_36 ) )
break;
V_21 -> type &= ~ ( V_36 | V_39 ) ;
V_21 = V_21 -> V_21 ;
}
F_10 ( L_6
L_7 ,
V_26 -> V_5 -> V_17 ,
V_26 -> V_31 >> 8 ,
F_27 ( V_26 -> V_31 & 0xFF ) ,
F_28 ( V_26 -> V_31 & 0xFF ) ,
V_6 -> V_30 , V_6 -> V_21 -> V_30 ) ;
return 0 ;
}
if ( V_26 -> V_34 )
V_6 = F_2 ( V_26 -> V_5 , V_40 ) ;
else
V_6 = F_2 ( V_26 -> V_5 , V_41 ) ;
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
F_29 ( V_6 ) ;
return - V_42 ;
}
}
V_6 -> V_21 = V_21 ;
F_9 ( & V_6 -> V_10 , & V_21 -> V_9 ) ;
F_9 ( & V_26 -> V_38 , & V_6 -> V_11 ) ;
V_26 -> V_6 = V_6 ;
F_10 ( L_9
L_10 ,
V_26 -> V_5 -> V_17 ,
V_26 -> V_31 >> 8 ,
F_27 ( V_26 -> V_31 & 0xFF ) ,
F_28 ( V_26 -> V_31 & 0xFF ) ,
V_6 -> V_30 , V_6 -> V_21 -> V_30 ) ;
return 0 ;
}
int F_30 ( struct V_25 * V_26 )
{
struct V_3 * V_6 , * V_21 , * V_10 ;
int V_43 ;
if ( ! V_26 -> V_6 ) {
F_10 ( L_11 ,
V_14 , V_26 -> V_5 -> V_17 ,
V_26 -> V_31 >> 8 ,
F_27 ( V_26 -> V_31 & 0xFF ) ,
F_28 ( V_26 -> V_31 & 0xFF ) ) ;
return - V_42 ;
}
V_6 = F_31 ( V_26 ) ;
V_26 -> V_6 = NULL ;
F_32 ( & V_26 -> V_38 ) ;
while ( 1 ) {
V_21 = V_6 -> V_21 ;
if ( V_6 -> type & V_13 )
break;
if ( ! ( V_6 -> V_44 & V_39 ) ) {
if ( F_33 ( & V_6 -> V_11 ) &&
F_33 ( & V_6 -> V_9 ) ) {
F_32 ( & V_6 -> V_10 ) ;
F_29 ( V_6 ) ;
} else {
break;
}
} else {
if ( F_33 ( & V_6 -> V_11 ) ) {
V_43 = 0 ;
F_12 (child, &pe->child_list, child) {
if ( ! ( V_10 -> type & V_36 ) ) {
V_43 ++ ;
break;
}
}
if ( ! V_43 )
V_6 -> type |= V_36 ;
else
break;
}
}
V_6 = V_21 ;
}
return 0 ;
}
void F_34 ( struct V_3 * V_6 )
{
struct V_45 V_46 ;
if ( ! V_6 ) return;
if ( V_6 -> V_47 <= 0 ) {
V_6 -> V_47 = 0 ;
F_35 ( & V_6 -> V_46 ) ;
} else {
F_35 ( & V_46 ) ;
if ( V_46 . V_48 - V_6 -> V_46 . V_48 > 3600 ) {
V_6 -> V_46 = V_46 ;
V_6 -> V_47 = 0 ;
}
}
}
static void * F_36 ( void * V_12 , void * V_23 )
{
struct V_3 * V_6 = (struct V_3 * ) V_12 ;
int V_44 = * ( ( int * ) V_23 ) ;
struct V_25 * V_26 , * V_27 ;
struct V_49 * V_50 ;
if ( V_6 -> V_44 & V_51 )
return NULL ;
V_6 -> V_44 |= V_44 ;
if ( ! ( V_44 & V_52 ) )
return NULL ;
F_18 (pe, edev, tmp) {
V_50 = F_37 ( V_26 ) ;
if ( V_50 )
V_50 -> V_53 = V_54 ;
}
if ( V_6 -> V_44 & V_55 )
V_6 -> V_44 |= V_56 ;
return NULL ;
}
void F_38 ( struct V_3 * V_6 , int V_44 )
{
F_15 ( V_6 , F_36 , & V_44 ) ;
}
static void * F_39 ( void * V_12 , void * V_23 )
{
struct V_25 * V_26 = V_12 ;
int V_57 = * ( ( int * ) V_23 ) ;
V_26 -> V_57 |= V_57 ;
return NULL ;
}
void F_40 ( struct V_3 * V_6 , int V_57 )
{
F_16 ( V_6 , F_39 , & V_57 ) ;
}
static void * F_41 ( void * V_12 , void * V_23 )
{
struct V_3 * V_6 = (struct V_3 * ) V_12 ;
int V_44 = * ( ( int * ) V_23 ) ;
struct V_25 * V_26 , * V_27 ;
struct V_49 * V_50 ;
if ( V_6 -> V_44 & V_51 )
return NULL ;
V_6 -> V_44 &= ~ V_44 ;
if ( ! ( V_44 & V_52 ) )
return NULL ;
V_6 -> V_58 = 0 ;
F_18 (pe, edev, tmp) {
V_50 = F_37 ( V_26 ) ;
if ( ! V_50 )
continue;
V_50 -> V_53 = V_59 ;
}
if ( V_6 -> V_44 & V_55 )
V_6 -> V_44 &= ~ V_56 ;
return NULL ;
}
void F_42 ( struct V_3 * V_6 , int V_44 )
{
F_15 ( V_6 , F_41 , & V_44 ) ;
}
void F_43 ( struct V_3 * V_6 , int V_44 )
{
F_15 ( V_6 , F_36 , & V_44 ) ;
if ( ! ( V_44 & V_52 ) )
return;
V_44 = V_56 ;
F_15 ( V_6 , F_41 , & V_44 ) ;
}
static void F_44 ( struct V_25 * V_26 )
{
struct V_32 * V_33 = F_23 ( V_26 ) ;
int V_60 ;
T_3 V_61 ;
int V_62 = 0 ;
if ( ! ( V_26 -> V_57 & ( V_63 | V_64 ) ) )
return;
F_10 ( L_12 ,
V_14 , V_26 -> V_5 -> V_17 ,
V_26 -> V_31 >> 8 ,
F_27 ( V_26 -> V_31 & 0xFF ) ,
F_28 ( V_26 -> V_31 & 0xFF ) ) ;
V_60 = V_26 -> V_65 ;
V_66 -> V_67 ( V_33 , V_60 + V_68 , 2 , & V_61 ) ;
if ( ! ( V_61 & V_69 ) ) {
F_10 ( L_13 , V_61 ) ;
return;
}
V_66 -> V_67 ( V_33 , V_60 + V_70 , 2 , & V_61 ) ;
if ( V_61 & V_71 ) {
V_66 -> V_67 ( V_33 , V_60 + V_72 , 2 , & V_61 ) ;
if ( V_61 & V_73 ) {
F_10 ( L_14 ) ;
V_61 &= ~ ( V_73 | V_74 ) ;
V_61 |= ( 0x0100 & V_74 ) ;
V_66 -> V_75 ( V_33 , V_60 + V_72 , 2 , V_61 ) ;
F_45 ( 2 * 1000 ) ;
}
}
V_66 -> V_67 ( V_33 , V_60 + V_76 , 2 , & V_61 ) ;
V_61 &= ~ V_77 ;
V_66 -> V_75 ( V_33 , V_60 + V_76 , 2 , V_61 ) ;
V_66 -> V_67 ( V_33 , V_60 + V_78 , 4 , & V_61 ) ;
if ( ! ( V_61 & V_79 ) ) {
F_10 ( L_15 , V_61 ) ;
F_45 ( 1000 ) ;
return;
}
V_62 = 0 ;
while ( V_62 < 5000 ) {
F_45 ( 20 ) ;
V_62 += 20 ;
V_66 -> V_67 ( V_33 , V_60 + V_80 , 2 , & V_61 ) ;
if ( V_61 & V_81 )
break;
}
if ( V_61 & V_81 )
F_10 ( L_16 ,
( V_61 & V_82 ) ? L_17 : L_18 ) ;
else
F_10 ( L_19 , V_61 ) ;
}
static void F_46 ( struct V_25 * V_26 )
{
struct V_32 * V_33 = F_23 ( V_26 ) ;
int V_83 ;
for ( V_83 = 4 ; V_83 < 13 ; V_83 ++ )
V_66 -> V_75 ( V_33 , V_83 * 4 , 4 , V_26 -> V_84 [ V_83 ] ) ;
V_66 -> V_75 ( V_33 , 14 * 4 , 4 , V_26 -> V_84 [ 14 ] ) ;
V_66 -> V_75 ( V_33 , V_85 , 1 ,
F_47 ( V_85 ) ) ;
V_66 -> V_75 ( V_33 , V_86 , 1 ,
F_47 ( V_86 ) ) ;
V_66 -> V_75 ( V_33 , 15 * 4 , 4 , V_26 -> V_84 [ 15 ] ) ;
V_66 -> V_75 ( V_33 , V_87 , 4 , V_26 -> V_84 [ 1 ] ) ;
F_44 ( V_26 ) ;
}
static void F_48 ( struct V_25 * V_26 )
{
struct V_32 * V_33 = F_23 ( V_26 ) ;
int V_83 ;
T_4 V_88 ;
for ( V_83 = 4 ; V_83 < 10 ; V_83 ++ )
V_66 -> V_75 ( V_33 , V_83 * 4 , 4 , V_26 -> V_84 [ V_83 ] ) ;
V_66 -> V_75 ( V_33 , 12 * 4 , 4 , V_26 -> V_84 [ 12 ] ) ;
V_66 -> V_75 ( V_33 , V_85 , 1 ,
F_47 ( V_85 ) ) ;
V_66 -> V_75 ( V_33 , V_86 , 1 ,
F_47 ( V_86 ) ) ;
V_66 -> V_75 ( V_33 , 15 * 4 , 4 , V_26 -> V_84 [ 15 ] ) ;
V_66 -> V_67 ( V_33 , V_87 , 4 , & V_88 ) ;
if ( V_26 -> V_84 [ 1 ] & V_89 )
V_88 |= V_89 ;
else
V_88 &= ~ V_89 ;
if ( V_26 -> V_84 [ 1 ] & V_90 )
V_88 |= V_90 ;
else
V_88 &= ~ V_90 ;
V_66 -> V_75 ( V_33 , V_87 , 4 , V_88 ) ;
}
static void * F_49 ( void * V_12 , void * V_23 )
{
struct V_25 * V_26 = (struct V_25 * ) V_12 ;
struct V_32 * V_33 = F_23 ( V_26 ) ;
if ( V_26 -> V_57 & V_91 )
F_46 ( V_26 ) ;
else
F_48 ( V_26 ) ;
if ( V_66 -> V_92 && V_33 )
V_66 -> V_92 ( V_33 ) ;
return NULL ;
}
void F_50 ( struct V_3 * V_6 )
{
F_16 ( V_6 , F_49 , NULL ) ;
}
const char * F_51 ( struct V_3 * V_6 )
{
struct V_93 * V_94 = F_52 ( V_6 ) ;
struct V_95 * V_96 ;
const char * V_97 = NULL ;
while ( V_94 ) {
V_96 = F_53 ( V_94 ) ;
if ( ! V_96 ) {
V_94 = V_94 -> V_21 ;
continue;
}
if ( F_54 ( V_94 ) )
V_97 = F_55 ( V_96 , L_20 , NULL ) ;
else
V_97 = F_55 ( V_96 , L_21 ,
NULL ) ;
if ( V_97 )
return V_97 ;
V_94 = V_94 -> V_21 ;
}
return L_22 ;
}
struct V_93 * F_52 ( struct V_3 * V_6 )
{
struct V_25 * V_26 ;
struct V_49 * V_50 ;
if ( V_6 -> type & V_13 )
return V_6 -> V_5 -> V_94 ;
if ( V_6 -> V_44 & V_98 )
return V_6 -> V_94 ;
V_26 = F_56 ( & V_6 -> V_11 , struct V_25 , V_38 ) ;
V_50 = F_37 ( V_26 ) ;
if ( V_50 )
return V_50 -> V_94 ;
return NULL ;
}
