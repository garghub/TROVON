static inline char F_1 ( int V_1 )
{
return 'A' + V_1 - 1 ;
}
static void F_2 ( struct V_2 * V_3 ,
struct V_4 * V_5 )
{
int V_6 ;
const struct V_7 * V_8 ;
for ( V_6 = 0 ; V_6 < F_3 ( V_9 ) ; V_6 ++ ) {
V_8 = & V_9 [ V_6 ] ;
if ( F_4 ( V_8 -> system ) &&
V_3 -> V_10 . V_11 == V_8 -> V_11 &&
V_3 -> V_10 . V_12 == V_8 -> V_12 &&
V_3 -> V_10 . V_13 == V_8 -> V_13 &&
V_3 -> V_1 == V_8 -> V_1 &&
! strcmp ( V_5 -> V_14 , V_8 -> V_14 ) &&
strlen ( V_5 -> V_14 ) >= strlen ( V_8 -> V_15 ) ) {
F_5 (KERN_WARNING PREFIX L_1
L_2
L_3 ,
entry->id.segment, entry->id.bus,
entry->id.device, pin_name(entry->pin),
prt->source, quirk->actual_source) ;
strcpy ( V_5 -> V_14 , V_8 -> V_15 ) ;
}
}
}
static int F_6 ( T_1 V_16 , struct V_17 * V_18 ,
int V_1 , struct V_4 * V_5 ,
struct V_2 * * V_19 )
{
int V_11 = F_7 ( V_18 -> V_12 ) ;
int V_12 = V_18 -> V_12 -> V_20 ;
int V_13 = F_8 ( V_18 -> V_12 ) ? 0 : F_9 ( V_18 -> V_21 ) ;
struct V_2 * V_3 ;
if ( ( ( V_5 -> V_22 >> 16 ) & 0xffff ) != V_13 ||
V_5 -> V_1 + 1 != V_1 )
return - V_23 ;
V_3 = F_10 ( sizeof( struct V_2 ) , V_24 ) ;
if ( ! V_3 )
return - V_25 ;
V_3 -> V_10 . V_11 = V_11 ;
V_3 -> V_10 . V_12 = V_12 ;
V_3 -> V_10 . V_13 = ( V_5 -> V_22 >> 16 ) & 0xFFFF ;
V_3 -> V_1 = V_5 -> V_1 + 1 ;
F_2 ( V_3 , V_5 ) ;
V_3 -> V_26 = V_5 -> V_27 ;
if ( V_5 -> V_14 [ 0 ] )
F_11 ( V_16 , V_5 -> V_14 , & V_3 -> V_28 ) ;
F_12 ( ( V_29 ,
L_4 ,
V_3 -> V_10 . V_11 , V_3 -> V_10 . V_12 ,
V_3 -> V_10 . V_13 , F_1 ( V_3 -> V_1 ) ,
V_5 -> V_14 , V_3 -> V_26 ) ) ;
* V_19 = V_3 ;
return 0 ;
}
static int F_13 ( struct V_17 * V_18 ,
int V_1 , struct V_2 * * V_19 )
{
T_2 V_30 ;
struct V_31 V_32 = { V_33 , NULL } ;
struct V_4 * V_3 ;
T_1 V_16 = NULL ;
if ( V_18 -> V_12 -> V_34 )
V_16 = F_14 ( V_18 -> V_12 -> V_34 ) ;
if ( ! V_16 )
return - V_23 ;
V_30 = F_15 ( V_16 , & V_32 ) ;
if ( F_16 ( V_30 ) ) {
F_17 ( V_32 . V_35 ) ;
return - V_23 ;
}
V_3 = V_32 . V_35 ;
while ( V_3 && ( V_3 -> V_36 > 0 ) ) {
if ( ! F_6 ( V_16 , V_18 , V_1 ,
V_3 , V_19 ) )
break;
V_3 = (struct V_4 * )
( ( unsigned long ) V_3 + V_3 -> V_36 ) ;
}
F_17 ( V_32 . V_35 ) ;
return 0 ;
}
static int F_18 ( struct V_37 * V_12 )
{
struct V_37 * V_38 ;
for ( V_38 = V_12 ; V_38 ; V_38 = V_38 -> V_39 ) {
if ( ! V_38 -> V_40 )
return 0 ;
if ( V_38 -> V_40 -> V_41 )
return V_38 -> V_40 -> V_41 ;
}
return 0 ;
}
static int F_19 ( struct V_17 * V_18 ,
struct V_2 * V_3 )
{
if ( V_42 || V_43 ) {
return 0 ;
} else {
switch ( F_18 ( V_18 -> V_12 ) ) {
case 0 :
return 0 ;
case V_44 :
F_20 ( & V_18 -> V_18 , L_5
L_6 , V_3 -> V_26 ,
( V_3 -> V_26 % 4 ) + 16 ) ;
V_3 -> V_26 = ( V_3 -> V_26 % 4 ) + 16 ;
return 1 ;
default:
F_21 ( & V_18 -> V_18 , L_7
L_8 , V_3 -> V_26 ) ;
return - 1 ;
}
}
}
static struct V_2 * F_22 ( struct V_17 * V_18 , int V_1 )
{
struct V_2 * V_3 = NULL ;
struct V_17 * V_34 ;
T_3 V_45 , V_46 = V_1 ;
int V_47 ;
V_47 = F_13 ( V_18 , V_1 , & V_3 ) ;
if ( ! V_47 && V_3 ) {
#ifdef F_23
F_19 ( V_18 , V_3 ) ;
#endif
F_24 ( ( V_29 , L_9 ,
F_25 ( V_18 ) , F_1 ( V_1 ) ) ) ;
return V_3 ;
}
V_34 = V_18 -> V_12 -> V_40 ;
while ( V_34 ) {
V_1 = F_26 ( V_18 , V_1 ) ;
if ( ( V_34 -> V_48 >> 8 ) == V_49 ) {
V_45 = V_34 -> V_1 ;
if ( ! V_45 ) {
F_24 ( ( V_29 ,
L_10 ,
F_25 ( V_34 ) ) ) ;
return NULL ;
}
V_1 = V_45 ;
}
V_47 = F_13 ( V_34 , V_1 , & V_3 ) ;
if ( ! V_47 && V_3 ) {
F_24 ( ( V_29 ,
L_11 ,
F_25 ( V_18 ) , F_1 ( V_46 ) ,
F_25 ( V_34 ) ) ) ;
return V_3 ;
}
V_18 = V_34 ;
V_34 = V_18 -> V_12 -> V_40 ;
}
F_21 ( & V_18 -> V_18 , L_12 ,
F_1 ( V_46 ) ) ;
return NULL ;
}
static int F_27 ( struct V_17 * V_18 )
{
T_4 V_50 ;
if ( V_18 -> V_51 > 0 && ( V_18 -> V_51 <= 0xF ) &&
F_28 ( V_18 -> V_51 ) &&
( F_29 ( V_18 -> V_51 , & V_50 ) == 0 ) ) {
F_21 ( & V_18 -> V_18 , L_13 ,
F_1 ( V_18 -> V_1 ) , V_18 -> V_51 ) ;
F_30 ( & V_18 -> V_18 , V_50 ,
V_52 ,
V_53 ) ;
return 0 ;
}
return - V_54 ;
}
static inline int F_27 ( struct V_17 * V_18 )
{
return - V_23 ;
}
static inline bool F_31 ( struct V_17 * V_18 , T_3 V_1 )
{
#ifdef F_32
if ( V_18 -> V_51 == 0xff ) {
V_18 -> V_51 = V_55 ;
F_21 ( & V_18 -> V_18 , L_14 ,
F_1 ( V_1 ) ) ;
return false ;
}
#endif
return true ;
}
int F_33 ( struct V_17 * V_18 )
{
struct V_2 * V_3 ;
int V_56 ;
T_3 V_1 ;
int V_57 = V_52 ;
int V_58 = V_53 ;
char * V_28 = NULL ;
char V_59 [ 16 ] ;
int V_60 ;
V_1 = V_18 -> V_1 ;
if ( ! V_1 ) {
F_24 ( ( V_29 ,
L_10 ,
F_25 ( V_18 ) ) ) ;
return 0 ;
}
if ( V_18 -> V_61 && V_18 -> V_51 > 0 )
return 0 ;
V_3 = F_22 ( V_18 , V_1 ) ;
if ( ! V_3 ) {
if ( V_18 -> V_48 >> 8 == V_62 &&
( V_18 -> V_48 & 0x05 ) == 0 )
return 0 ;
}
if ( V_3 ) {
if ( V_3 -> V_28 )
V_56 = F_34 ( V_3 -> V_28 ,
V_3 -> V_26 ,
& V_57 , & V_58 ,
& V_28 ) ;
else
V_56 = V_3 -> V_26 ;
} else
V_56 = - 1 ;
if ( V_56 < 0 ) {
if ( ! F_31 ( V_18 , V_1 ) )
return 0 ;
if ( F_27 ( V_18 ) )
F_21 ( & V_18 -> V_18 , L_15 ,
F_1 ( V_1 ) ) ;
F_17 ( V_3 ) ;
return 0 ;
}
V_60 = F_30 ( & V_18 -> V_18 , V_56 , V_57 , V_58 ) ;
if ( V_60 < 0 ) {
F_21 ( & V_18 -> V_18 , L_16 ,
F_1 ( V_1 ) ) ;
F_17 ( V_3 ) ;
return V_60 ;
}
V_18 -> V_51 = V_60 ;
V_18 -> V_61 = 1 ;
if ( V_28 )
snprintf ( V_59 , sizeof( V_59 ) , L_17 , V_28 ) ;
else
V_59 [ 0 ] = '\0' ;
F_35 ( & V_18 -> V_18 , L_18 ,
F_1 ( V_1 ) , V_59 , V_56 ,
( V_57 == V_52 ) ? L_19 : L_20 ,
( V_58 == V_53 ) ? L_21 : L_22 , V_18 -> V_51 ) ;
F_17 ( V_3 ) ;
return 0 ;
}
void F_36 ( struct V_17 * V_18 )
{
struct V_2 * V_3 ;
int V_56 ;
T_3 V_1 ;
V_1 = V_18 -> V_1 ;
if ( ! V_1 || ! V_18 -> V_61 || V_18 -> V_51 <= 0 )
return;
if ( V_18 -> V_18 . V_63 . V_64 )
return;
#ifdef F_37
if ( V_18 -> V_18 . V_63 . V_65 == V_66 )
return;
#endif
V_3 = F_22 ( V_18 , V_1 ) ;
if ( ! V_3 )
return;
if ( V_3 -> V_28 )
V_56 = F_38 ( V_3 -> V_28 ) ;
else
V_56 = V_3 -> V_26 ;
F_17 ( V_3 ) ;
F_35 ( & V_18 -> V_18 , L_23 , F_1 ( V_1 ) ) ;
if ( V_56 >= 0 ) {
F_39 ( V_56 ) ;
V_18 -> V_61 = 0 ;
}
}
