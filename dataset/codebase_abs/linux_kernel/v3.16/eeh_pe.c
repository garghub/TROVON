static struct V_1 * F_1 ( struct V_2 * V_3 , int type )
{
struct V_1 * V_4 ;
V_4 = F_2 ( sizeof( struct V_1 ) , V_5 ) ;
if ( ! V_4 ) return NULL ;
V_4 -> type = type ;
V_4 -> V_3 = V_3 ;
F_3 ( & V_4 -> V_6 ) ;
F_3 ( & V_4 -> V_7 ) ;
F_3 ( & V_4 -> V_8 ) ;
return V_4 ;
}
int F_4 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
V_4 = F_1 ( V_3 , V_9 ) ;
if ( ! V_4 ) {
F_5 ( L_1 , V_10 ) ;
return - V_11 ;
}
F_6 ( & V_4 -> V_7 , & V_12 ) ;
F_7 ( L_2 , V_3 -> V_13 ) ;
return 0 ;
}
struct V_1 * F_8 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
F_9 (pe, &eeh_phb_pe, child) {
if ( ( V_4 -> type & V_9 ) && V_4 -> V_3 == V_3 )
return V_4 ;
}
return NULL ;
}
static struct V_1 * F_10 ( struct V_1 * V_4 ,
struct V_1 * V_14 )
{
struct V_15 * V_16 = V_4 -> V_6 . V_16 ;
if ( V_16 == & V_4 -> V_6 ) {
while ( 1 ) {
if ( V_4 == V_14 )
return NULL ;
V_16 = V_4 -> V_7 . V_16 ;
if ( V_16 != & V_4 -> V_17 -> V_6 )
break;
V_4 = V_4 -> V_17 ;
}
}
return F_11 ( V_16 , struct V_1 , V_7 ) ;
}
void * F_12 ( struct V_1 * V_14 ,
T_1 V_18 , void * V_19 )
{
struct V_1 * V_4 ;
void * V_20 ;
for ( V_4 = V_14 ; V_4 ; V_4 = F_10 ( V_4 , V_14 ) ) {
V_20 = V_18 ( V_4 , V_19 ) ;
if ( V_20 ) return V_20 ;
}
return NULL ;
}
void * F_13 ( struct V_1 * V_14 ,
T_1 V_18 , void * V_19 )
{
struct V_1 * V_4 ;
struct V_21 * V_22 , * V_23 ;
void * V_20 ;
if ( ! V_14 ) {
F_14 ( L_3 , V_10 , V_14 ) ;
return NULL ;
}
for ( V_4 = V_14 ; V_4 ; V_4 = F_10 ( V_4 , V_14 ) ) {
F_15 (pe, edev, tmp) {
V_20 = V_18 ( V_22 , V_19 ) ;
if ( V_20 )
return V_20 ;
}
}
return NULL ;
}
static void * F_16 ( void * V_24 , void * V_19 )
{
struct V_1 * V_4 = (struct V_1 * ) V_24 ;
struct V_21 * V_22 = (struct V_21 * ) V_19 ;
if ( V_4 -> type & V_9 )
return NULL ;
if ( V_22 -> V_25 &&
( V_22 -> V_25 == V_4 -> V_26 ) )
return V_4 ;
if ( V_22 -> V_27 &&
( V_22 -> V_27 == V_4 -> V_27 ) )
return V_4 ;
return NULL ;
}
struct V_1 * F_17 ( struct V_21 * V_22 )
{
struct V_1 * V_14 = F_8 ( V_22 -> V_3 ) ;
struct V_1 * V_4 ;
V_4 = F_12 ( V_14 , F_16 , V_22 ) ;
return V_4 ;
}
static struct V_1 * F_18 ( struct V_21 * V_22 )
{
struct V_28 * V_29 ;
struct V_21 * V_17 ;
V_29 = V_22 -> V_29 -> V_17 ;
while ( V_29 ) {
if ( ! F_19 ( V_29 ) ) return NULL ;
V_17 = F_20 ( V_29 ) ;
if ( ! V_17 ) return NULL ;
if ( V_17 -> V_4 )
return V_17 -> V_4 ;
V_29 = V_29 -> V_17 ;
}
return NULL ;
}
int F_21 ( struct V_21 * V_22 )
{
struct V_1 * V_4 , * V_17 ;
V_4 = F_17 ( V_22 ) ;
if ( V_4 && ! ( V_4 -> type & V_30 ) ) {
if ( ! V_22 -> V_25 ) {
F_5 ( L_4 ,
V_10 , V_22 -> V_27 ) ;
return - V_31 ;
}
V_4 -> type = V_32 ;
V_22 -> V_4 = V_4 ;
F_6 ( & V_22 -> V_33 , & V_4 -> V_8 ) ;
F_7 ( L_5 ,
V_22 -> V_29 -> V_34 , V_4 -> V_26 ) ;
return 0 ;
} else if ( V_4 && ( V_4 -> type & V_30 ) ) {
F_6 ( & V_22 -> V_33 , & V_4 -> V_8 ) ;
V_22 -> V_4 = V_4 ;
V_17 = V_4 ;
while ( V_17 ) {
if ( ! ( V_17 -> type & V_30 ) )
break;
V_17 -> type &= ~ ( V_30 | V_35 ) ;
V_17 = V_17 -> V_17 ;
}
F_7 ( L_6 ,
V_22 -> V_29 -> V_34 , V_4 -> V_26 , V_4 -> V_17 -> V_26 ) ;
return 0 ;
}
V_4 = F_1 ( V_22 -> V_3 , V_36 ) ;
if ( ! V_4 ) {
F_5 ( L_1 , V_10 ) ;
return - V_11 ;
}
V_4 -> V_26 = V_22 -> V_25 ;
V_4 -> V_27 = V_22 -> V_27 ;
if ( F_22 () )
V_4 -> V_37 = F_23 ( V_22 ) -> V_37 ;
V_17 = F_18 ( V_22 ) ;
if ( ! V_17 ) {
V_17 = F_8 ( V_22 -> V_3 ) ;
if ( ! V_17 ) {
F_5 ( L_7 ,
V_10 , V_22 -> V_3 -> V_13 ) ;
V_22 -> V_4 = NULL ;
F_24 ( V_4 ) ;
return - V_31 ;
}
}
V_4 -> V_17 = V_17 ;
F_6 ( & V_4 -> V_7 , & V_17 -> V_6 ) ;
F_6 ( & V_22 -> V_33 , & V_4 -> V_8 ) ;
V_22 -> V_4 = V_4 ;
F_7 ( L_6 ,
V_22 -> V_29 -> V_34 , V_4 -> V_26 , V_4 -> V_17 -> V_26 ) ;
return 0 ;
}
int F_25 ( struct V_21 * V_22 )
{
struct V_1 * V_4 , * V_17 , * V_7 ;
int V_38 ;
if ( ! V_22 -> V_4 ) {
F_7 ( L_8 ,
V_10 , V_22 -> V_29 -> V_34 ) ;
return - V_31 ;
}
V_4 = V_22 -> V_4 ;
V_22 -> V_4 = NULL ;
F_26 ( & V_22 -> V_33 ) ;
while ( 1 ) {
V_17 = V_4 -> V_17 ;
if ( V_4 -> type & V_9 )
break;
if ( ! ( V_4 -> V_39 & V_35 ) ) {
if ( F_27 ( & V_4 -> V_8 ) &&
F_27 ( & V_4 -> V_6 ) ) {
F_26 ( & V_4 -> V_7 ) ;
F_24 ( V_4 ) ;
} else {
break;
}
} else {
if ( F_27 ( & V_4 -> V_8 ) ) {
V_38 = 0 ;
F_9 (child, &pe->child_list, child) {
if ( ! ( V_7 -> type & V_30 ) ) {
V_38 ++ ;
break;
}
}
if ( ! V_38 )
V_4 -> type |= V_30 ;
else
break;
}
}
V_4 = V_17 ;
}
return 0 ;
}
void F_28 ( struct V_1 * V_4 )
{
struct V_40 V_41 ;
if ( ! V_4 ) return;
if ( V_4 -> V_42 <= 0 ) {
V_4 -> V_42 = 0 ;
F_29 ( & V_4 -> V_41 ) ;
} else {
F_29 ( & V_41 ) ;
if ( V_41 . V_43 - V_4 -> V_41 . V_43 > 3600 ) {
V_4 -> V_41 = V_41 ;
V_4 -> V_42 = 0 ;
}
}
}
static void * F_30 ( void * V_24 , void * V_19 )
{
struct V_1 * V_4 = (struct V_1 * ) V_24 ;
int V_39 = * ( ( int * ) V_19 ) ;
struct V_21 * V_22 , * V_23 ;
struct V_44 * V_45 ;
if ( ( V_4 -> V_42 > V_46 ) &&
( V_39 & ( V_47 | V_48 ) ) )
return NULL ;
V_4 -> V_39 |= V_39 ;
if ( V_39 != V_47 )
return NULL ;
F_15 (pe, edev, tmp) {
V_45 = F_23 ( V_22 ) ;
if ( V_45 )
V_45 -> V_49 = V_50 ;
}
return NULL ;
}
void F_31 ( struct V_1 * V_4 , int V_39 )
{
F_12 ( V_4 , F_30 , & V_39 ) ;
}
static void * F_32 ( void * V_24 , void * V_19 )
{
struct V_21 * V_22 = V_24 ;
int V_51 = * ( ( int * ) V_19 ) ;
V_22 -> V_51 |= V_51 ;
return NULL ;
}
void F_33 ( struct V_1 * V_4 , int V_51 )
{
F_13 ( V_4 , F_32 , & V_51 ) ;
}
static void * F_34 ( void * V_24 , void * V_19 )
{
struct V_1 * V_4 = (struct V_1 * ) V_24 ;
int V_39 = * ( ( int * ) V_19 ) ;
if ( ( V_4 -> V_42 > V_46 ) &&
( V_39 & V_47 ) )
return NULL ;
V_4 -> V_39 &= ~ V_39 ;
if ( V_39 & V_47 )
V_4 -> V_52 = 0 ;
return NULL ;
}
void F_35 ( struct V_1 * V_4 , int V_39 )
{
F_12 ( V_4 , F_34 , & V_39 ) ;
}
static void F_36 ( struct V_21 * V_22 ,
struct V_28 * V_29 )
{
int V_53 ;
T_2 V_54 ;
int V_55 = 0 ;
if ( ! ( V_22 -> V_51 & ( V_56 | V_57 ) ) )
return;
F_7 ( L_9 ,
V_10 , V_22 -> V_3 -> V_13 ,
V_22 -> V_27 >> 8 ,
F_37 ( V_22 -> V_27 & 0xFF ) ,
F_38 ( V_22 -> V_27 & 0xFF ) ) ;
V_53 = V_22 -> V_58 ;
V_59 -> V_60 ( V_29 , V_53 + V_61 , 2 , & V_54 ) ;
if ( ! ( V_54 & V_62 ) ) {
F_7 ( L_10 , V_54 ) ;
return;
}
V_59 -> V_60 ( V_29 , V_53 + V_63 , 2 , & V_54 ) ;
if ( V_54 & V_64 ) {
V_59 -> V_60 ( V_29 , V_53 + V_65 , 2 , & V_54 ) ;
if ( V_54 & V_66 ) {
F_7 ( L_11 ) ;
V_54 &= ~ ( V_66 | V_67 ) ;
V_54 |= ( 0x0100 & V_67 ) ;
V_59 -> V_68 ( V_29 , V_53 + V_65 , 2 , V_54 ) ;
F_39 ( 2 * 1000 ) ;
}
}
V_59 -> V_60 ( V_29 , V_53 + V_69 , 2 , & V_54 ) ;
V_54 &= ~ V_70 ;
V_59 -> V_68 ( V_29 , V_53 + V_69 , 2 , V_54 ) ;
V_59 -> V_60 ( V_29 , V_53 + V_71 , 4 , & V_54 ) ;
if ( ! ( V_54 & V_72 ) ) {
F_7 ( L_12 , V_54 ) ;
F_39 ( 1000 ) ;
return;
}
V_55 = 0 ;
while ( V_55 < 5000 ) {
F_39 ( 20 ) ;
V_55 += 20 ;
V_59 -> V_60 ( V_29 , V_53 + V_73 , 2 , & V_54 ) ;
if ( V_54 & V_74 )
break;
}
if ( V_54 & V_74 )
F_7 ( L_13 ,
( V_54 & V_75 ) ? L_14 : L_15 ) ;
else
F_7 ( L_16 , V_54 ) ;
}
static void F_40 ( struct V_21 * V_22 ,
struct V_28 * V_29 )
{
int V_76 ;
for ( V_76 = 4 ; V_76 < 13 ; V_76 ++ )
V_59 -> V_68 ( V_29 , V_76 * 4 , 4 , V_22 -> V_77 [ V_76 ] ) ;
V_59 -> V_68 ( V_29 , 14 * 4 , 4 , V_22 -> V_77 [ 14 ] ) ;
V_59 -> V_68 ( V_29 , V_78 , 1 ,
F_41 ( V_78 ) ) ;
V_59 -> V_68 ( V_29 , V_79 , 1 ,
F_41 ( V_79 ) ) ;
V_59 -> V_68 ( V_29 , 15 * 4 , 4 , V_22 -> V_77 [ 15 ] ) ;
V_59 -> V_68 ( V_29 , V_80 , 4 , V_22 -> V_77 [ 1 ] ) ;
F_36 ( V_22 , V_29 ) ;
}
static void F_42 ( struct V_21 * V_22 ,
struct V_28 * V_29 )
{
int V_76 ;
T_3 V_81 ;
for ( V_76 = 4 ; V_76 < 10 ; V_76 ++ )
V_59 -> V_68 ( V_29 , V_76 * 4 , 4 , V_22 -> V_77 [ V_76 ] ) ;
V_59 -> V_68 ( V_29 , 12 * 4 , 4 , V_22 -> V_77 [ 12 ] ) ;
V_59 -> V_68 ( V_29 , V_78 , 1 ,
F_41 ( V_78 ) ) ;
V_59 -> V_68 ( V_29 , V_79 , 1 ,
F_41 ( V_79 ) ) ;
V_59 -> V_68 ( V_29 , 15 * 4 , 4 , V_22 -> V_77 [ 15 ] ) ;
V_59 -> V_60 ( V_29 , V_80 , 4 , & V_81 ) ;
if ( V_22 -> V_77 [ 1 ] & V_82 )
V_81 |= V_82 ;
else
V_81 &= ~ V_82 ;
if ( V_22 -> V_77 [ 1 ] & V_83 )
V_81 |= V_83 ;
else
V_81 &= ~ V_83 ;
V_59 -> V_68 ( V_29 , V_80 , 4 , V_81 ) ;
}
static void * F_43 ( void * V_24 , void * V_19 )
{
struct V_21 * V_22 = (struct V_21 * ) V_24 ;
struct V_28 * V_29 = F_44 ( V_22 ) ;
if ( V_22 -> V_51 & V_84 )
F_40 ( V_22 , V_29 ) ;
else
F_42 ( V_22 , V_29 ) ;
if ( V_59 -> V_85 )
V_59 -> V_85 ( V_29 ) ;
return NULL ;
}
void F_45 ( struct V_1 * V_4 )
{
F_13 ( V_4 , F_43 , NULL ) ;
}
const char * F_46 ( struct V_1 * V_4 )
{
struct V_2 * V_86 ;
struct V_87 * V_37 = F_47 ( V_4 ) ;
struct V_44 * V_45 ;
struct V_28 * V_29 ;
const char * V_88 ;
if ( ! V_37 )
return L_17 ;
if ( F_48 ( V_37 ) ) {
V_86 = F_49 ( V_37 ) ;
V_88 = F_50 ( V_86 -> V_29 ,
L_18 , NULL ) ;
if ( V_88 )
return V_88 ;
V_88 = F_50 ( V_86 -> V_29 ,
L_19 , NULL ) ;
if ( V_88 )
return V_88 ;
V_45 = F_51 ( V_37 , 0x0 ) ;
} else {
V_45 = V_37 -> V_89 ;
}
if ( ! V_45 ) {
V_88 = L_17 ;
goto V_90;
}
V_29 = F_52 ( V_45 ) ;
if ( ! V_29 ) {
V_88 = L_17 ;
goto V_90;
}
V_88 = F_50 ( V_29 , L_18 , NULL ) ;
if ( ! V_88 )
V_88 = F_50 ( V_29 , L_20 , NULL ) ;
if ( ! V_88 )
V_88 = L_17 ;
V_90:
if ( F_48 ( V_37 ) && V_45 )
F_53 ( V_45 ) ;
return V_88 ;
}
struct V_87 * F_47 ( struct V_1 * V_4 )
{
struct V_87 * V_37 = NULL ;
struct V_21 * V_22 ;
struct V_44 * V_45 ;
if ( V_4 -> type & V_9 ) {
V_37 = V_4 -> V_3 -> V_37 ;
} else if ( V_4 -> type & V_32 ||
V_4 -> type & V_36 ) {
if ( V_4 -> V_37 ) {
V_37 = V_4 -> V_37 ;
goto V_90;
}
V_22 = F_54 ( & V_4 -> V_8 , struct V_21 , V_33 ) ;
V_45 = F_23 ( V_22 ) ;
if ( V_45 )
V_37 = V_45 -> V_37 ;
}
V_90:
return V_37 ;
}
