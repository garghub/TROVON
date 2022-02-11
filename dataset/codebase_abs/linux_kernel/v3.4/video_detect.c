static T_1
F_1 ( T_2 V_1 , T_3 V_2 , void * V_3 ,
void * * V_4 )
{
long * V_5 = V_3 ;
T_2 V_6 ;
if ( F_2 ( F_3 ( V_1 , L_1 , & V_6 ) ) &&
F_2 ( F_3 ( V_1 , L_2 , & V_6 ) ) ) {
F_4 ( ( V_7 , L_3
L_4 ) ) ;
* V_5 |= V_8 ;
if ( F_5 ( F_3 ( V_1 , L_5 , & V_6 ) ) )
F_6 (KERN_WARNING FW_BUG PREFIX L_6
L_7 ) ;
return V_9 ;
}
return 0 ;
}
long F_7 ( struct V_10 * V_11 )
{
T_2 V_6 ;
long V_12 = 0 ;
if ( ! V_11 )
return 0 ;
if ( F_2 ( F_3 ( V_11 -> V_1 , L_8 , & V_6 ) ) ||
F_2 ( F_3 ( V_11 -> V_1 , L_9 , & V_6 ) ) )
V_12 |= V_13 ;
if ( F_2 ( F_3 ( V_11 -> V_1 , L_10 , & V_6 ) ) )
V_12 |= V_14 ;
if ( F_2 ( F_3 ( V_11 -> V_1 , L_11 , & V_6 ) ) &&
F_2 ( F_3 ( V_11 -> V_1 , L_12 , & V_6 ) ) &&
F_2 ( F_3 ( V_11 -> V_1 , L_13 , & V_6 ) ) )
V_12 |= V_15 ;
if ( V_12 )
F_8 ( V_16 , V_11 -> V_1 ,
V_17 , F_1 , NULL ,
& V_12 , NULL ) ;
return V_12 ;
}
static T_1
F_9 ( T_2 V_1 , T_3 V_18 , void * V_3 , void * * V_19 )
{
long * V_5 = V_3 ;
struct V_20 * V_21 ;
struct V_10 * V_22 ;
const struct V_23 V_24 [] = {
{ V_25 , 0 } ,
{ L_14 , 0 } ,
} ;
if ( F_10 ( V_1 , & V_22 ) )
return V_26 ;
if ( ! F_11 ( V_22 , V_24 ) ) {
V_21 = F_12 ( V_1 ) ;
if ( ! V_21 )
return V_26 ;
F_13 ( V_21 ) ;
* V_5 |= F_7 ( V_22 ) ;
}
return V_26 ;
}
long F_14 ( T_2 V_27 )
{
long V_28 = 0 ;
struct V_10 * V_29 ;
T_1 V_30 ;
if ( V_31 && V_27 == NULL )
return V_32 ;
if ( ! V_27 ) {
F_8 ( V_16 , V_33 ,
V_17 , F_9 , NULL ,
& V_28 , NULL ) ;
V_32 |= V_28 ;
V_31 = 1 ;
} else {
V_30 = F_10 ( V_27 , & V_29 ) ;
if ( F_5 ( V_30 ) ) {
F_15 ( ( V_34 , V_30 , L_15 ) ) ;
return 0 ;
}
F_8 ( V_16 , V_27 ,
V_17 , F_9 , NULL ,
& V_28 , NULL ) ;
}
F_4 ( ( V_7 , L_16 ,
V_27 ? V_28 : V_32 ,
V_27 ? L_17 : L_18 ,
V_27 ? F_16 ( V_29 ) : L_14 ) ) ;
return V_28 ;
}
int F_17 ( void )
{
if ( ! V_31 )
F_14 ( NULL ) ;
if ( V_32 & V_35 )
return 0 ;
else if ( V_32 & V_36 )
return 1 ;
if ( V_32 & V_37 )
return 0 ;
else if ( V_32 & V_38 )
return 1 ;
return V_32 & V_8 ;
}
static int T_4 F_18 ( char * V_39 )
{
if ( V_39 == NULL || * V_39 == '\0' )
return 1 ;
else {
if ( ! strcmp ( L_19 , V_39 ) )
V_32 |=
V_35 ;
if ( ! strcmp ( L_20 , V_39 ) )
V_32 |=
V_36 ;
}
return 1 ;
}
