static inline char F_1 ( int V_1 )
{
return 'A' + V_1 - 1 ;
}
static struct V_2 * F_2 ( struct V_3 * V_4 ,
int V_1 )
{
struct V_2 * V_5 ;
int V_6 = F_3 ( V_4 -> V_7 ) ;
int V_7 = V_4 -> V_7 -> V_8 ;
int V_9 = F_4 ( V_4 -> V_10 ) ;
F_5 ( & V_11 ) ;
F_6 (entry, &acpi_prt_list, list) {
if ( ( V_6 == V_5 -> V_12 . V_6 )
&& ( V_7 == V_5 -> V_12 . V_7 )
&& ( V_9 == V_5 -> V_12 . V_9 )
&& ( V_1 == V_5 -> V_1 ) ) {
F_7 ( & V_11 ) ;
return V_5 ;
}
}
F_7 ( & V_11 ) ;
return NULL ;
}
static void F_8 ( struct V_2 * V_5 ,
struct V_13 * V_14 )
{
int V_15 ;
const struct V_16 * V_17 ;
for ( V_15 = 0 ; V_15 < F_9 ( V_18 ) ; V_15 ++ ) {
V_17 = & V_18 [ V_15 ] ;
if ( ! V_14 -> V_19 )
continue;
if ( F_10 ( V_17 -> system ) &&
V_5 -> V_12 . V_6 == V_17 -> V_6 &&
V_5 -> V_12 . V_7 == V_17 -> V_7 &&
V_5 -> V_12 . V_9 == V_17 -> V_9 &&
V_5 -> V_1 == V_17 -> V_1 &&
! strcmp ( V_14 -> V_19 , V_17 -> V_19 ) &&
strlen ( V_14 -> V_19 ) >= strlen ( V_17 -> V_20 ) ) {
F_11 (KERN_WARNING PREFIX L_1
L_2
L_3 ,
entry->id.segment, entry->id.bus,
entry->id.device, pin_name(entry->pin),
prt->source, quirk->actual_source) ;
strcpy ( V_14 -> V_19 , V_17 -> V_20 ) ;
}
}
}
static int F_12 ( T_1 V_21 , struct V_22 * V_7 ,
struct V_13 * V_14 )
{
struct V_2 * V_5 ;
V_5 = F_13 ( sizeof( struct V_2 ) , V_23 ) ;
if ( ! V_5 )
return - V_24 ;
V_5 -> V_12 . V_6 = F_3 ( V_7 ) ;
V_5 -> V_12 . V_7 = V_7 -> V_8 ;
V_5 -> V_12 . V_9 = ( V_14 -> V_25 >> 16 ) & 0xFFFF ;
V_5 -> V_1 = V_14 -> V_1 + 1 ;
F_8 ( V_5 , V_14 ) ;
V_5 -> V_26 = V_14 -> V_27 ;
if ( V_14 -> V_19 [ 0 ] )
F_14 ( V_21 , V_14 -> V_19 , & V_5 -> V_28 ) ;
F_15 ( ( V_29 ,
L_4 ,
V_5 -> V_12 . V_6 , V_5 -> V_12 . V_7 ,
V_5 -> V_12 . V_9 , F_1 ( V_5 -> V_1 ) ,
V_14 -> V_19 , V_5 -> V_26 ) ) ;
F_5 ( & V_11 ) ;
F_16 ( & V_5 -> V_30 , & V_31 ) ;
F_7 ( & V_11 ) ;
return 0 ;
}
int F_17 ( T_1 V_21 , struct V_22 * V_7 )
{
T_2 V_32 ;
struct V_33 V_34 = { V_35 , NULL } ;
struct V_13 * V_5 ;
V_32 = F_18 ( V_21 , V_36 , & V_34 ) ;
if ( F_19 ( V_32 ) )
return - V_37 ;
F_11 ( V_38 L_5 ,
( char * ) V_34 . V_39 ) ;
F_20 ( V_34 . V_39 ) ;
V_34 . V_40 = V_35 ;
V_34 . V_39 = NULL ;
V_32 = F_21 ( V_21 , & V_34 ) ;
if ( F_19 ( V_32 ) ) {
F_22 ( ( V_41 , V_32 , L_6 ,
F_23 ( V_32 ) ) ) ;
F_20 ( V_34 . V_39 ) ;
return - V_37 ;
}
V_5 = V_34 . V_39 ;
while ( V_5 && ( V_5 -> V_40 > 0 ) ) {
F_12 ( V_21 , V_7 , V_5 ) ;
V_5 = (struct V_13 * )
( ( unsigned long ) V_5 + V_5 -> V_40 ) ;
}
F_20 ( V_34 . V_39 ) ;
return 0 ;
}
void F_24 ( struct V_22 * V_7 )
{
struct V_2 * V_5 , * V_42 ;
F_11 ( V_38
L_7 ,
F_3 ( V_7 ) , V_7 -> V_8 ) ;
F_5 ( & V_11 ) ;
F_25 (entry, tmp, &acpi_prt_list, list) {
if ( F_3 ( V_7 ) == V_5 -> V_12 . V_6
&& V_7 -> V_8 == V_5 -> V_12 . V_7 ) {
F_26 ( & V_5 -> V_30 ) ;
F_20 ( V_5 ) ;
}
}
F_7 ( & V_11 ) ;
}
static int F_27 ( struct V_22 * V_7 )
{
struct V_22 * V_43 ;
for ( V_43 = V_7 ; V_43 ; V_43 = V_43 -> V_44 ) {
if ( ! V_43 -> V_45 )
return 0 ;
if ( V_43 -> V_45 -> V_46 )
return V_43 -> V_45 -> V_46 ;
}
return 0 ;
}
static int F_28 ( struct V_3 * V_4 ,
struct V_2 * V_5 )
{
if ( V_47 || V_48 ) {
return 0 ;
} else {
switch ( F_27 ( V_4 -> V_7 ) ) {
case 0 :
return 0 ;
case V_49 :
F_29 ( & V_4 -> V_4 , L_8
L_9 , V_5 -> V_26 ,
( V_5 -> V_26 % 4 ) + 16 ) ;
V_5 -> V_26 = ( V_5 -> V_26 % 4 ) + 16 ;
return 1 ;
default:
F_30 ( & V_4 -> V_4 , L_10
L_11 , V_5 -> V_26 ) ;
return - 1 ;
}
}
}
static struct V_2 * F_31 ( struct V_3 * V_4 , int V_1 )
{
struct V_2 * V_5 ;
struct V_3 * V_50 ;
T_3 V_51 , V_52 = V_1 ;
V_5 = F_2 ( V_4 , V_1 ) ;
if ( V_5 ) {
#ifdef F_32
F_28 ( V_4 , V_5 ) ;
#endif
F_33 ( ( V_29 , L_12 ,
F_34 ( V_4 ) , F_1 ( V_1 ) ) ) ;
return V_5 ;
}
V_50 = V_4 -> V_7 -> V_45 ;
while ( V_50 ) {
V_1 = F_35 ( V_4 , V_1 ) ;
if ( ( V_50 -> V_53 >> 8 ) == V_54 ) {
V_51 = V_50 -> V_1 ;
if ( ! V_51 ) {
F_33 ( ( V_29 ,
L_13 ,
F_34 ( V_50 ) ) ) ;
return NULL ;
}
V_1 = V_51 ;
}
V_5 = F_2 ( V_50 , V_1 ) ;
if ( V_5 ) {
F_33 ( ( V_29 ,
L_14 ,
F_34 ( V_4 ) , F_1 ( V_52 ) ,
F_34 ( V_50 ) ) ) ;
return V_5 ;
}
V_4 = V_50 ;
V_50 = V_4 -> V_7 -> V_45 ;
}
F_30 ( & V_4 -> V_4 , L_15 ,
F_1 ( V_52 ) ) ;
return NULL ;
}
int F_36 ( struct V_3 * V_4 )
{
struct V_2 * V_5 ;
int V_55 ;
T_3 V_1 ;
int V_56 = V_57 ;
int V_58 = V_59 ;
char * V_28 = NULL ;
char V_60 [ 16 ] ;
int V_61 ;
V_1 = V_4 -> V_1 ;
if ( ! V_1 ) {
F_33 ( ( V_29 ,
L_13 ,
F_34 ( V_4 ) ) ) ;
return 0 ;
}
V_5 = F_31 ( V_4 , V_1 ) ;
if ( ! V_5 ) {
if ( V_4 -> V_53 >> 8 == V_62 &&
( V_4 -> V_53 & 0x05 ) == 0 )
return 0 ;
}
if ( V_5 ) {
if ( V_5 -> V_28 )
V_55 = F_37 ( V_5 -> V_28 ,
V_5 -> V_26 ,
& V_56 , & V_58 ,
& V_28 ) ;
else
V_55 = V_5 -> V_26 ;
} else
V_55 = - 1 ;
if ( V_55 < 0 ) {
T_4 V_63 ;
F_30 ( & V_4 -> V_4 , L_16 , F_1 ( V_1 ) ) ;
if ( V_4 -> V_64 > 0 && ( V_4 -> V_64 <= 0xF ) &&
( F_38 ( V_4 -> V_64 , & V_63 ) == 0 ) ) {
F_11 ( L_17 , V_4 -> V_64 ) ;
F_39 ( & V_4 -> V_4 , V_63 ,
V_57 ,
V_59 ) ;
return 0 ;
} else {
F_11 ( L_18 ) ;
return 0 ;
}
}
V_61 = F_39 ( & V_4 -> V_4 , V_55 , V_56 , V_58 ) ;
if ( V_61 < 0 ) {
F_30 ( & V_4 -> V_4 , L_19 ,
F_1 ( V_1 ) ) ;
return V_61 ;
}
V_4 -> V_64 = V_61 ;
if ( V_28 )
snprintf ( V_60 , sizeof( V_60 ) , L_20 , V_28 ) ;
else
V_60 [ 0 ] = '\0' ;
F_29 ( & V_4 -> V_4 , L_21 ,
F_1 ( V_1 ) , V_60 , V_55 ,
( V_56 == V_57 ) ? L_22 : L_23 ,
( V_58 == V_59 ) ? L_24 : L_25 , V_4 -> V_64 ) ;
return 0 ;
}
void F_40 ( struct V_3 * V_4 )
{
struct V_2 * V_5 ;
int V_55 ;
T_3 V_1 ;
V_1 = V_4 -> V_1 ;
if ( ! V_1 )
return;
V_5 = F_31 ( V_4 , V_1 ) ;
if ( ! V_5 )
return;
if ( V_5 -> V_28 )
V_55 = F_41 ( V_5 -> V_28 ) ;
else
V_55 = V_5 -> V_26 ;
F_29 ( & V_4 -> V_4 , L_26 , F_1 ( V_1 ) ) ;
F_42 ( V_55 ) ;
}
