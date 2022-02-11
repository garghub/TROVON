void F_1 ( enum V_1 V_2 , const char * V_3 )
{
if ( ! V_4 ) {
F_2 ( L_1 ) ;
} else {
F_3 ( V_5 -> V_6 ,
V_4 +
V_5 -> V_7 ) ;
F_3 ( V_5 -> V_8 ,
V_4 +
V_5 -> V_9 ) ;
}
while ( 1 )
;
}
int F_4 ( T_1 * V_10 , T_1 * V_11 )
{
if ( F_5 ( L_2 ) &&
V_4 ) {
* V_10 = F_6 ( V_4 + V_5 -> V_12 ) >> 16 ;
* V_11 = ( F_6 ( V_4 + V_5 -> V_13 ) >> 8 )
& 0xF ;
return 0 ;
} else
return - V_14 ;
}
static void F_7 ( void )
{
T_1 V_10 , V_11 ;
T_2 V_15 ;
if ( F_8 ( & V_10 , & V_11 ) != 0 )
return;
if ( V_11 != V_16 )
return;
V_15 = V_17 +
V_5 -> V_18 ;
F_9 ( V_19 ,
V_20 ,
V_15 ) ;
}
void F_10 ( void * V_21 )
{
F_11 ( V_4 == NULL ) ;
F_11 ( V_5 -> V_18 == 0 ) ;
if ( F_5 ( L_3 ) )
F_7 () ;
F_3 ( F_12 ( V_21 ) , V_4 +
V_5 -> V_18 ) ;
}
static int T_3 F_13 ( void )
{
const struct V_22 * V_23 ;
struct V_24 * V_25 ;
V_25 = F_14 ( NULL , V_26 ,
& V_23 ) ;
if ( V_25 ) {
struct V_27 V_28 ;
V_4 = F_15 ( V_25 , 0 ) ;
F_16 ( V_25 , 0 , & V_28 ) ;
V_17 = V_28 . V_29 ;
V_5 = (struct V_30 * ) V_23 -> V_31 ;
F_17 ( V_25 ) ;
}
return 0 ;
}
