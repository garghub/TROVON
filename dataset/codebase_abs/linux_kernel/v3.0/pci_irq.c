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
static struct V_2 * F_27 ( struct V_3 * V_4 , int V_1 )
{
struct V_2 * V_5 ;
struct V_3 * V_43 ;
T_3 V_44 , V_45 = V_1 ;
V_5 = F_2 ( V_4 , V_1 ) ;
if ( V_5 ) {
F_28 ( ( V_29 , L_8 ,
F_29 ( V_4 ) , F_1 ( V_1 ) ) ) ;
return V_5 ;
}
V_43 = V_4 -> V_7 -> V_46 ;
while ( V_43 ) {
V_1 = F_30 ( V_4 , V_1 ) ;
if ( ( V_43 -> V_47 >> 8 ) == V_48 ) {
V_44 = V_43 -> V_1 ;
if ( ! V_44 ) {
F_28 ( ( V_29 ,
L_9 ,
F_29 ( V_43 ) ) ) ;
return NULL ;
}
V_1 = V_44 ;
}
V_5 = F_2 ( V_43 , V_1 ) ;
if ( V_5 ) {
F_28 ( ( V_29 ,
L_10 ,
F_29 ( V_4 ) , F_1 ( V_45 ) ,
F_29 ( V_43 ) ) ) ;
return V_5 ;
}
V_4 = V_43 ;
V_43 = V_4 -> V_7 -> V_46 ;
}
F_31 ( & V_4 -> V_4 , L_11 ,
F_1 ( V_45 ) ) ;
return NULL ;
}
int F_32 ( struct V_3 * V_4 )
{
struct V_2 * V_5 ;
int V_49 ;
T_3 V_1 ;
int V_50 = V_51 ;
int V_52 = V_53 ;
char * V_28 = NULL ;
char V_54 [ 16 ] ;
int V_55 ;
V_1 = V_4 -> V_1 ;
if ( ! V_1 ) {
F_28 ( ( V_29 ,
L_9 ,
F_29 ( V_4 ) ) ) ;
return 0 ;
}
V_5 = F_27 ( V_4 , V_1 ) ;
if ( ! V_5 ) {
if ( V_4 -> V_47 >> 8 == V_56 &&
( V_4 -> V_47 & 0x05 ) == 0 )
return 0 ;
}
if ( V_5 ) {
if ( V_5 -> V_28 )
V_49 = F_33 ( V_5 -> V_28 ,
V_5 -> V_26 ,
& V_50 , & V_52 ,
& V_28 ) ;
else
V_49 = V_5 -> V_26 ;
} else
V_49 = - 1 ;
if ( V_49 < 0 ) {
T_4 V_57 ;
F_31 ( & V_4 -> V_4 , L_12 , F_1 ( V_1 ) ) ;
if ( V_4 -> V_58 > 0 && ( V_4 -> V_58 <= 0xF ) &&
( F_34 ( V_4 -> V_58 , & V_57 ) == 0 ) ) {
F_11 ( L_13 , V_4 -> V_58 ) ;
F_35 ( & V_4 -> V_4 , V_57 ,
V_51 ,
V_53 ) ;
return 0 ;
} else {
F_11 ( L_14 ) ;
return 0 ;
}
}
V_55 = F_35 ( & V_4 -> V_4 , V_49 , V_50 , V_52 ) ;
if ( V_55 < 0 ) {
F_31 ( & V_4 -> V_4 , L_15 ,
F_1 ( V_1 ) ) ;
return V_55 ;
}
V_4 -> V_58 = V_55 ;
if ( V_28 )
snprintf ( V_54 , sizeof( V_54 ) , L_16 , V_28 ) ;
else
V_54 [ 0 ] = '\0' ;
F_36 ( & V_4 -> V_4 , L_17 ,
F_1 ( V_1 ) , V_54 , V_49 ,
( V_50 == V_51 ) ? L_18 : L_19 ,
( V_52 == V_53 ) ? L_20 : L_21 , V_4 -> V_58 ) ;
return 0 ;
}
void F_37 ( struct V_3 * V_4 )
{
struct V_2 * V_5 ;
int V_49 ;
T_3 V_1 ;
V_1 = V_4 -> V_1 ;
if ( ! V_1 )
return;
V_5 = F_27 ( V_4 , V_1 ) ;
if ( ! V_5 )
return;
if ( V_5 -> V_28 )
V_49 = F_38 ( V_5 -> V_28 ) ;
else
V_49 = V_5 -> V_26 ;
F_36 ( & V_4 -> V_4 , L_22 , F_1 ( V_1 ) ) ;
F_39 ( V_49 ) ;
}
