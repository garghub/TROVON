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
V_4 -> V_39 |= V_39 ;
F_15 (pe, edev, tmp) {
V_45 = F_23 ( V_22 ) ;
if ( V_45 )
V_45 -> V_46 = V_47 ;
}
return NULL ;
}
void F_31 ( struct V_1 * V_4 , int V_39 )
{
F_12 ( V_4 , F_30 , & V_39 ) ;
}
static void * F_32 ( void * V_24 , void * V_19 )
{
struct V_1 * V_4 = (struct V_1 * ) V_24 ;
int V_39 = * ( ( int * ) V_19 ) ;
V_4 -> V_39 &= ~ V_39 ;
V_4 -> V_48 = 0 ;
return NULL ;
}
void F_33 ( struct V_1 * V_4 , int V_39 )
{
F_12 ( V_4 , F_32 , & V_39 ) ;
}
static void F_34 ( struct V_21 * V_22 ,
struct V_28 * V_29 )
{
int V_49 ;
T_2 V_50 ;
int V_51 = 0 ;
if ( ! ( V_22 -> V_52 & ( V_53 | V_54 ) ) )
return;
F_7 ( L_9 ,
V_10 , V_22 -> V_3 -> V_13 ,
V_22 -> V_27 >> 8 ,
F_35 ( V_22 -> V_27 & 0xFF ) ,
F_36 ( V_22 -> V_27 & 0xFF ) ) ;
V_49 = V_22 -> V_55 ;
V_56 -> V_57 ( V_29 , V_49 + V_58 , 2 , & V_50 ) ;
if ( ! ( V_50 & V_59 ) ) {
F_7 ( L_10 , V_50 ) ;
return;
}
V_56 -> V_57 ( V_29 , V_49 + V_60 , 2 , & V_50 ) ;
if ( V_50 & V_61 ) {
V_56 -> V_57 ( V_29 , V_49 + V_62 , 2 , & V_50 ) ;
if ( V_50 & V_63 ) {
F_7 ( L_11 ) ;
V_50 &= ~ ( V_63 | V_64 ) ;
V_50 |= ( 0x0100 & V_64 ) ;
V_56 -> V_65 ( V_29 , V_49 + V_62 , 2 , V_50 ) ;
F_37 ( 2 * 1000 ) ;
}
}
V_56 -> V_57 ( V_29 , V_49 + V_66 , 2 , & V_50 ) ;
V_50 &= ~ V_67 ;
V_56 -> V_65 ( V_29 , V_49 + V_66 , 2 , V_50 ) ;
V_56 -> V_57 ( V_29 , V_49 + V_68 , 4 , & V_50 ) ;
if ( ! ( V_50 & V_69 ) ) {
F_7 ( L_12 , V_50 ) ;
F_37 ( 1000 ) ;
return;
}
V_51 = 0 ;
while ( V_51 < 5000 ) {
F_37 ( 20 ) ;
V_51 += 20 ;
V_56 -> V_57 ( V_29 , V_49 + V_70 , 2 , & V_50 ) ;
if ( V_50 & V_71 )
break;
}
if ( V_50 & V_71 )
F_7 ( L_13 ,
( V_50 & V_72 ) ? L_14 : L_15 ) ;
else
F_7 ( L_16 , V_50 ) ;
}
static void F_38 ( struct V_21 * V_22 ,
struct V_28 * V_29 )
{
int V_73 ;
for ( V_73 = 4 ; V_73 < 13 ; V_73 ++ )
V_56 -> V_65 ( V_29 , V_73 * 4 , 4 , V_22 -> V_74 [ V_73 ] ) ;
V_56 -> V_65 ( V_29 , 14 * 4 , 4 , V_22 -> V_74 [ 14 ] ) ;
V_56 -> V_65 ( V_29 , V_75 , 1 ,
F_39 ( V_75 ) ) ;
V_56 -> V_65 ( V_29 , V_76 , 1 ,
F_39 ( V_76 ) ) ;
V_56 -> V_65 ( V_29 , 15 * 4 , 4 , V_22 -> V_74 [ 15 ] ) ;
V_56 -> V_65 ( V_29 , V_77 , 4 , V_22 -> V_74 [ 1 ] ) ;
F_34 ( V_22 , V_29 ) ;
}
static void F_40 ( struct V_21 * V_22 ,
struct V_28 * V_29 )
{
int V_73 ;
T_3 V_78 ;
for ( V_73 = 4 ; V_73 < 10 ; V_73 ++ )
V_56 -> V_65 ( V_29 , V_73 * 4 , 4 , V_22 -> V_74 [ V_73 ] ) ;
V_56 -> V_65 ( V_29 , 12 * 4 , 4 , V_22 -> V_74 [ 12 ] ) ;
V_56 -> V_65 ( V_29 , V_75 , 1 ,
F_39 ( V_75 ) ) ;
V_56 -> V_65 ( V_29 , V_76 , 1 ,
F_39 ( V_76 ) ) ;
V_56 -> V_65 ( V_29 , 15 * 4 , 4 , V_22 -> V_74 [ 15 ] ) ;
V_56 -> V_57 ( V_29 , V_77 , 4 , & V_78 ) ;
if ( V_22 -> V_74 [ 1 ] & V_79 )
V_78 |= V_79 ;
else
V_78 &= ~ V_79 ;
if ( V_22 -> V_74 [ 1 ] & V_80 )
V_78 |= V_80 ;
else
V_78 &= ~ V_80 ;
V_56 -> V_65 ( V_29 , V_77 , 4 , V_78 ) ;
}
static void * F_41 ( void * V_24 , void * V_19 )
{
struct V_21 * V_22 = (struct V_21 * ) V_24 ;
struct V_28 * V_29 = F_42 ( V_22 ) ;
if ( V_22 -> V_52 & V_81 )
F_38 ( V_22 , V_29 ) ;
else
F_40 ( V_22 , V_29 ) ;
if ( V_56 -> V_82 )
V_56 -> V_82 ( V_29 ) ;
return NULL ;
}
void F_43 ( struct V_1 * V_4 )
{
F_13 ( V_4 , F_41 , NULL ) ;
}
struct V_83 * F_44 ( struct V_1 * V_4 )
{
struct V_83 * V_37 = NULL ;
struct V_21 * V_22 ;
struct V_44 * V_45 ;
if ( V_4 -> type & V_9 ) {
V_37 = V_4 -> V_3 -> V_37 ;
} else if ( V_4 -> type & V_32 ||
V_4 -> type & V_36 ) {
if ( V_4 -> V_37 ) {
V_37 = V_4 -> V_37 ;
goto V_84;
}
V_22 = F_45 ( & V_4 -> V_8 , struct V_21 , V_33 ) ;
V_45 = F_23 ( V_22 ) ;
if ( V_45 )
V_37 = V_45 -> V_37 ;
}
V_84:
return V_37 ;
}
