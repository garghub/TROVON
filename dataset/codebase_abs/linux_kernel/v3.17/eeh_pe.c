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
if ( V_26 -> V_28 &&
( V_26 -> V_28 == V_6 -> V_29 ) )
return V_6 ;
if ( V_26 -> V_30 &&
( V_26 -> V_30 == V_6 -> V_30 ) )
return V_6 ;
return NULL ;
}
struct V_3 * F_20 ( struct V_25 * V_26 )
{
struct V_3 * V_18 = F_11 ( V_26 -> V_5 ) ;
struct V_3 * V_6 ;
V_6 = F_15 ( V_18 , F_19 , V_26 ) ;
return V_6 ;
}
static struct V_3 * F_21 ( struct V_25 * V_26 )
{
struct V_31 * V_32 ;
struct V_25 * V_21 ;
V_32 = V_26 -> V_32 -> V_21 ;
while ( V_32 ) {
if ( ! F_22 ( V_32 ) ) return NULL ;
V_21 = F_23 ( V_32 ) ;
if ( ! V_21 ) return NULL ;
if ( V_21 -> V_6 )
return V_21 -> V_6 ;
V_32 = V_32 -> V_21 ;
}
return NULL ;
}
int F_24 ( struct V_25 * V_26 )
{
struct V_3 * V_6 , * V_21 ;
V_6 = F_20 ( V_26 ) ;
if ( V_6 && ! ( V_6 -> type & V_33 ) ) {
if ( ! V_26 -> V_28 ) {
F_8 ( L_4 ,
V_14 , V_26 -> V_30 ) ;
return - V_34 ;
}
V_6 -> type = V_35 ;
V_26 -> V_6 = V_6 ;
F_9 ( & V_26 -> V_36 , & V_6 -> V_11 ) ;
F_10 ( L_5 ,
V_26 -> V_32 -> V_37 , V_6 -> V_29 ) ;
return 0 ;
} else if ( V_6 && ( V_6 -> type & V_33 ) ) {
F_9 ( & V_26 -> V_36 , & V_6 -> V_11 ) ;
V_26 -> V_6 = V_6 ;
V_21 = V_6 ;
while ( V_21 ) {
if ( ! ( V_21 -> type & V_33 ) )
break;
V_21 -> type &= ~ ( V_33 | V_38 ) ;
V_21 = V_21 -> V_21 ;
}
F_10 ( L_6 ,
V_26 -> V_32 -> V_37 , V_6 -> V_29 , V_6 -> V_21 -> V_29 ) ;
return 0 ;
}
V_6 = F_2 ( V_26 -> V_5 , V_39 ) ;
if ( ! V_6 ) {
F_8 ( L_1 , V_14 ) ;
return - V_15 ;
}
V_6 -> V_29 = V_26 -> V_28 ;
V_6 -> V_30 = V_26 -> V_30 ;
V_21 = F_21 ( V_26 ) ;
if ( ! V_21 ) {
V_21 = F_11 ( V_26 -> V_5 ) ;
if ( ! V_21 ) {
F_8 ( L_7 ,
V_14 , V_26 -> V_5 -> V_17 ) ;
V_26 -> V_6 = NULL ;
F_25 ( V_6 ) ;
return - V_34 ;
}
}
V_6 -> V_21 = V_21 ;
F_9 ( & V_6 -> V_10 , & V_21 -> V_9 ) ;
F_9 ( & V_26 -> V_36 , & V_6 -> V_11 ) ;
V_26 -> V_6 = V_6 ;
F_10 ( L_6 ,
V_26 -> V_32 -> V_37 , V_6 -> V_29 , V_6 -> V_21 -> V_29 ) ;
return 0 ;
}
int F_26 ( struct V_25 * V_26 )
{
struct V_3 * V_6 , * V_21 , * V_10 ;
int V_40 ;
if ( ! V_26 -> V_6 ) {
F_10 ( L_8 ,
V_14 , V_26 -> V_32 -> V_37 ) ;
return - V_34 ;
}
V_6 = V_26 -> V_6 ;
V_26 -> V_6 = NULL ;
F_27 ( & V_26 -> V_36 ) ;
while ( 1 ) {
V_21 = V_6 -> V_21 ;
if ( V_6 -> type & V_13 )
break;
if ( ! ( V_6 -> V_41 & V_38 ) ) {
if ( F_28 ( & V_6 -> V_11 ) &&
F_28 ( & V_6 -> V_9 ) ) {
F_27 ( & V_6 -> V_10 ) ;
F_25 ( V_6 ) ;
} else {
break;
}
} else {
if ( F_28 ( & V_6 -> V_11 ) ) {
V_40 = 0 ;
F_12 (child, &pe->child_list, child) {
if ( ! ( V_10 -> type & V_33 ) ) {
V_40 ++ ;
break;
}
}
if ( ! V_40 )
V_6 -> type |= V_33 ;
else
break;
}
}
V_6 = V_21 ;
}
return 0 ;
}
void F_29 ( struct V_3 * V_6 )
{
struct V_42 V_43 ;
if ( ! V_6 ) return;
if ( V_6 -> V_44 <= 0 ) {
V_6 -> V_44 = 0 ;
F_30 ( & V_6 -> V_43 ) ;
} else {
F_30 ( & V_43 ) ;
if ( V_43 . V_45 - V_6 -> V_43 . V_45 > 3600 ) {
V_6 -> V_43 = V_43 ;
V_6 -> V_44 = 0 ;
}
}
}
static void * F_31 ( void * V_12 , void * V_23 )
{
struct V_3 * V_6 = (struct V_3 * ) V_12 ;
int V_41 = * ( ( int * ) V_23 ) ;
struct V_25 * V_26 , * V_27 ;
struct V_46 * V_47 ;
if ( ( V_6 -> V_44 > V_48 ) &&
( V_41 & ( V_49 | V_50 ) ) )
return NULL ;
V_6 -> V_41 |= V_41 ;
if ( V_41 != V_49 )
return NULL ;
F_18 (pe, edev, tmp) {
V_47 = F_32 ( V_26 ) ;
if ( V_47 )
V_47 -> V_51 = V_52 ;
}
return NULL ;
}
void F_33 ( struct V_3 * V_6 , int V_41 )
{
F_15 ( V_6 , F_31 , & V_41 ) ;
}
static void * F_34 ( void * V_12 , void * V_23 )
{
struct V_25 * V_26 = V_12 ;
int V_53 = * ( ( int * ) V_23 ) ;
V_26 -> V_53 |= V_53 ;
return NULL ;
}
void F_35 ( struct V_3 * V_6 , int V_53 )
{
F_16 ( V_6 , F_34 , & V_53 ) ;
}
static void * F_36 ( void * V_12 , void * V_23 )
{
struct V_3 * V_6 = (struct V_3 * ) V_12 ;
int V_41 = * ( ( int * ) V_23 ) ;
if ( ( V_6 -> V_44 > V_48 ) &&
( V_41 & V_49 ) )
return NULL ;
V_6 -> V_41 &= ~ V_41 ;
if ( V_41 & V_49 )
V_6 -> V_54 = 0 ;
return NULL ;
}
void F_37 ( struct V_3 * V_6 , int V_41 )
{
F_15 ( V_6 , F_36 , & V_41 ) ;
}
static void F_38 ( struct V_25 * V_26 ,
struct V_31 * V_32 )
{
int V_55 ;
T_3 V_56 ;
int V_57 = 0 ;
if ( ! ( V_26 -> V_53 & ( V_58 | V_59 ) ) )
return;
F_10 ( L_9 ,
V_14 , V_26 -> V_5 -> V_17 ,
V_26 -> V_30 >> 8 ,
F_39 ( V_26 -> V_30 & 0xFF ) ,
F_40 ( V_26 -> V_30 & 0xFF ) ) ;
V_55 = V_26 -> V_60 ;
V_61 -> V_62 ( V_32 , V_55 + V_63 , 2 , & V_56 ) ;
if ( ! ( V_56 & V_64 ) ) {
F_10 ( L_10 , V_56 ) ;
return;
}
V_61 -> V_62 ( V_32 , V_55 + V_65 , 2 , & V_56 ) ;
if ( V_56 & V_66 ) {
V_61 -> V_62 ( V_32 , V_55 + V_67 , 2 , & V_56 ) ;
if ( V_56 & V_68 ) {
F_10 ( L_11 ) ;
V_56 &= ~ ( V_68 | V_69 ) ;
V_56 |= ( 0x0100 & V_69 ) ;
V_61 -> V_70 ( V_32 , V_55 + V_67 , 2 , V_56 ) ;
F_41 ( 2 * 1000 ) ;
}
}
V_61 -> V_62 ( V_32 , V_55 + V_71 , 2 , & V_56 ) ;
V_56 &= ~ V_72 ;
V_61 -> V_70 ( V_32 , V_55 + V_71 , 2 , V_56 ) ;
V_61 -> V_62 ( V_32 , V_55 + V_73 , 4 , & V_56 ) ;
if ( ! ( V_56 & V_74 ) ) {
F_10 ( L_12 , V_56 ) ;
F_41 ( 1000 ) ;
return;
}
V_57 = 0 ;
while ( V_57 < 5000 ) {
F_41 ( 20 ) ;
V_57 += 20 ;
V_61 -> V_62 ( V_32 , V_55 + V_75 , 2 , & V_56 ) ;
if ( V_56 & V_76 )
break;
}
if ( V_56 & V_76 )
F_10 ( L_13 ,
( V_56 & V_77 ) ? L_14 : L_15 ) ;
else
F_10 ( L_16 , V_56 ) ;
}
static void F_42 ( struct V_25 * V_26 ,
struct V_31 * V_32 )
{
int V_78 ;
for ( V_78 = 4 ; V_78 < 13 ; V_78 ++ )
V_61 -> V_70 ( V_32 , V_78 * 4 , 4 , V_26 -> V_79 [ V_78 ] ) ;
V_61 -> V_70 ( V_32 , 14 * 4 , 4 , V_26 -> V_79 [ 14 ] ) ;
V_61 -> V_70 ( V_32 , V_80 , 1 ,
F_43 ( V_80 ) ) ;
V_61 -> V_70 ( V_32 , V_81 , 1 ,
F_43 ( V_81 ) ) ;
V_61 -> V_70 ( V_32 , 15 * 4 , 4 , V_26 -> V_79 [ 15 ] ) ;
V_61 -> V_70 ( V_32 , V_82 , 4 , V_26 -> V_79 [ 1 ] ) ;
F_38 ( V_26 , V_32 ) ;
}
static void F_44 ( struct V_25 * V_26 ,
struct V_31 * V_32 )
{
int V_78 ;
T_4 V_83 ;
for ( V_78 = 4 ; V_78 < 10 ; V_78 ++ )
V_61 -> V_70 ( V_32 , V_78 * 4 , 4 , V_26 -> V_79 [ V_78 ] ) ;
V_61 -> V_70 ( V_32 , 12 * 4 , 4 , V_26 -> V_79 [ 12 ] ) ;
V_61 -> V_70 ( V_32 , V_80 , 1 ,
F_43 ( V_80 ) ) ;
V_61 -> V_70 ( V_32 , V_81 , 1 ,
F_43 ( V_81 ) ) ;
V_61 -> V_70 ( V_32 , 15 * 4 , 4 , V_26 -> V_79 [ 15 ] ) ;
V_61 -> V_62 ( V_32 , V_82 , 4 , & V_83 ) ;
if ( V_26 -> V_79 [ 1 ] & V_84 )
V_83 |= V_84 ;
else
V_83 &= ~ V_84 ;
if ( V_26 -> V_79 [ 1 ] & V_85 )
V_83 |= V_85 ;
else
V_83 &= ~ V_85 ;
V_61 -> V_70 ( V_32 , V_82 , 4 , V_83 ) ;
}
static void * F_45 ( void * V_12 , void * V_23 )
{
struct V_25 * V_26 = (struct V_25 * ) V_12 ;
struct V_31 * V_32 = F_46 ( V_26 ) ;
if ( V_26 -> V_53 & V_86 )
F_42 ( V_26 , V_32 ) ;
else
F_44 ( V_26 , V_32 ) ;
if ( V_61 -> V_87 )
V_61 -> V_87 ( V_32 ) ;
return NULL ;
}
void F_47 ( struct V_3 * V_6 )
{
F_16 ( V_6 , F_45 , NULL ) ;
}
const char * F_48 ( struct V_3 * V_6 )
{
struct V_88 * V_89 = F_49 ( V_6 ) ;
struct V_31 * V_32 = F_50 ( V_89 ) ;
const char * V_90 = NULL ;
if ( ! V_32 )
goto V_91;
if ( F_51 ( V_89 ) ) {
V_90 = F_52 ( V_32 , L_17 , NULL ) ;
if ( ! V_90 )
V_90 = F_52 ( V_32 , L_18 , NULL ) ;
if ( V_90 )
goto V_91;
V_32 = V_32 -> V_10 ;
if ( ! V_32 )
goto V_91;
}
V_90 = F_52 ( V_32 , L_17 , NULL ) ;
if ( ! V_90 )
V_90 = F_52 ( V_32 , L_19 , NULL ) ;
V_91:
return V_90 ? V_90 : L_20 ;
}
struct V_88 * F_49 ( struct V_3 * V_6 )
{
struct V_88 * V_89 = NULL ;
struct V_25 * V_26 ;
struct V_46 * V_47 ;
if ( V_6 -> type & V_13 ) {
V_89 = V_6 -> V_5 -> V_89 ;
} else if ( V_6 -> type & V_35 ||
V_6 -> type & V_39 ) {
if ( V_6 -> V_89 ) {
V_89 = V_6 -> V_89 ;
goto V_91;
}
V_26 = F_53 ( & V_6 -> V_11 , struct V_25 , V_36 ) ;
V_47 = F_32 ( V_26 ) ;
if ( V_47 )
V_89 = V_47 -> V_89 ;
}
V_91:
return V_89 ;
}
