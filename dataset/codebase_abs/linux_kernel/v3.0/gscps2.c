static int F_1 ( char * V_1 )
{
int V_2 = 25000 ;
while ( F_2 ( V_1 ) & V_3 ) {
if ( ! -- V_2 )
return 0 ;
F_3 ( 10 ) ;
}
return 1 ;
}
static void F_4 ( struct V_4 * V_5 )
{
while ( F_2 ( V_5 -> V_1 ) & V_6 )
F_5 ( V_5 -> V_1 ) ;
V_5 -> V_7 = V_5 -> V_8 = 0 ;
}
static inline int F_6 ( struct V_4 * V_5 , T_1 V_9 )
{
unsigned long V_10 ;
char * V_1 = V_5 -> V_1 ;
if ( ! F_1 ( V_1 ) ) {
F_7 (KERN_DEBUG PFX L_1 , data) ;
return 0 ;
}
while ( F_2 ( V_5 -> V_1 ) & V_6 )
;
F_8 ( & V_5 -> V_11 , V_10 ) ;
F_9 ( V_9 , V_1 + V_12 ) ;
F_10 ( & V_5 -> V_11 , V_10 ) ;
F_11 ( 6 ) ;
F_12 ( 0 , NULL ) ;
return 1 ;
}
static void F_13 ( struct V_4 * V_5 , int V_13 )
{
unsigned long V_10 ;
T_1 V_9 ;
F_8 ( & V_5 -> V_11 , V_10 ) ;
F_4 ( V_5 ) ;
V_9 = F_14 ( V_5 -> V_1 ) ;
if ( V_13 )
V_9 |= V_14 ;
else
V_9 &= ~ V_14 ;
F_15 ( V_9 , V_5 -> V_1 ) ;
F_10 ( & V_5 -> V_11 , V_10 ) ;
F_1 ( V_5 -> V_1 ) ;
F_4 ( V_5 ) ;
}
static void F_16 ( struct V_4 * V_5 )
{
char * V_1 = V_5 -> V_1 ;
unsigned long V_10 ;
F_8 ( & V_5 -> V_11 , V_10 ) ;
F_4 ( V_5 ) ;
F_9 ( 0xff , V_1 + V_15 ) ;
F_4 ( V_5 ) ;
F_10 ( & V_5 -> V_11 , V_10 ) ;
}
static T_2 F_12 ( int V_16 , void * V_17 )
{
struct V_4 * V_5 ;
F_17 (ps2port, &ps2port_list, node) {
unsigned long V_10 ;
F_8 ( & V_5 -> V_11 , V_10 ) ;
while ( ( V_5 -> V_18 [ V_5 -> V_8 ] . V_19 =
F_2 ( V_5 -> V_1 ) ) & V_6 ) {
V_5 -> V_18 [ V_5 -> V_8 ] . V_9 =
F_5 ( V_5 -> V_1 ) ;
V_5 -> V_8 = ( ( V_5 -> V_8 + 1 ) & V_20 ) ;
}
F_10 ( & V_5 -> V_11 , V_10 ) ;
}
F_17 (ps2port, &ps2port_list, node) {
while ( V_5 -> V_7 != V_5 -> V_8 ) {
unsigned int V_21 ;
T_1 V_9 , V_22 ;
if ( F_2 ( V_5 -> V_1 ) & V_23 )
return V_24 ;
V_22 = V_5 -> V_18 [ V_5 -> V_7 ] . V_19 ;
V_9 = V_5 -> V_18 [ V_5 -> V_7 ] . V_9 ;
V_5 -> V_7 = ( ( V_5 -> V_7 + 1 ) & V_20 ) ;
V_21 = ( ( V_22 & V_25 ) ? V_26 : 0 ) |
( ( V_22 & V_27 ) ? V_28 : 0 ) ;
F_18 ( V_5 -> V_29 , V_9 , V_21 ) ;
}
}
return V_24 ;
}
static int F_19 ( struct V_30 * V_29 , unsigned char V_9 )
{
struct V_4 * V_5 = V_29 -> V_31 ;
if ( ! F_6 ( V_5 , V_9 ) ) {
F_7 (KERN_DEBUG PFX L_2 , data) ;
return - 1 ;
}
return 0 ;
}
static int F_20 ( struct V_30 * V_29 )
{
struct V_4 * V_5 = V_29 -> V_31 ;
F_16 ( V_5 ) ;
F_13 ( V_5 , V_32 ) ;
F_12 ( 0 , NULL ) ;
return 0 ;
}
static void F_21 ( struct V_30 * V_29 )
{
struct V_4 * V_5 = V_29 -> V_31 ;
F_13 ( V_5 , V_33 ) ;
}
static int T_3 F_22 ( struct V_34 * V_17 )
{
struct V_4 * V_5 ;
struct V_30 * V_30 ;
unsigned long V_35 = V_17 -> V_35 . V_36 ;
int V_37 ;
if ( ! V_17 -> V_16 )
return - V_38 ;
if ( V_17 -> V_39 . V_40 == 0x96 )
V_35 += V_41 ;
V_5 = F_23 ( sizeof( struct V_4 ) , V_42 ) ;
V_30 = F_23 ( sizeof( struct V_30 ) , V_42 ) ;
if ( ! V_5 || ! V_30 ) {
V_37 = - V_43 ;
goto V_44;
}
F_24 ( & V_17 -> V_17 , V_5 ) ;
V_5 -> V_29 = V_30 ;
V_5 -> V_45 = V_17 ;
V_5 -> V_1 = F_25 ( V_35 , V_46 + 4 ) ;
F_26 ( & V_5 -> V_11 ) ;
F_16 ( V_5 ) ;
V_5 -> V_39 = F_27 ( V_5 -> V_1 + V_47 ) & 0x0f ;
snprintf ( V_30 -> V_48 , sizeof( V_30 -> V_48 ) , L_3 ,
( V_5 -> V_39 == V_49 ) ? L_4 : L_5 ) ;
F_28 ( V_30 -> V_50 , F_29 ( & V_17 -> V_17 ) , sizeof( V_30 -> V_50 ) ) ;
V_30 -> V_39 . type = V_51 ;
V_30 -> V_52 = F_19 ;
V_30 -> V_53 = F_20 ;
V_30 -> V_54 = F_21 ;
V_30 -> V_31 = V_5 ;
V_30 -> V_17 . V_55 = & V_17 -> V_17 ;
V_37 = - V_56 ;
if ( F_30 ( V_17 -> V_16 , F_12 , V_57 , V_5 -> V_29 -> V_48 , V_5 ) )
goto V_58;
if ( V_5 -> V_39 != V_49 && V_5 -> V_39 != V_59 ) {
F_7 (KERN_WARNING PFX L_6 ,
hpa, ps2port->id) ;
V_37 = - V_38 ;
goto V_60;
}
#if 0
if (!request_mem_region(hpa, GSC_STATUS + 4, ps2port->port.name))
goto fail;
#endif
F_7 ( V_61 L_7 ,
V_5 -> V_29 -> V_48 ,
V_5 -> V_1 ,
V_5 -> V_45 -> V_16 ,
V_5 -> V_29 -> V_50 ) ;
F_31 ( V_5 -> V_29 ) ;
F_32 ( & V_5 -> V_62 , & V_63 ) ;
return 0 ;
V_60:
F_33 ( V_17 -> V_16 , V_5 ) ;
V_58:
F_34 ( V_5 -> V_1 ) ;
F_35 ( V_17 -> V_35 . V_36 , V_46 + 4 ) ;
V_44:
F_36 ( V_5 ) ;
F_36 ( V_30 ) ;
return V_37 ;
}
static int T_4 F_37 ( struct V_34 * V_17 )
{
struct V_4 * V_5 = F_38 ( & V_17 -> V_17 ) ;
F_39 ( V_5 -> V_29 ) ;
F_33 ( V_17 -> V_16 , V_5 ) ;
F_4 ( V_5 ) ;
F_40 ( & V_5 -> V_62 ) ;
F_34 ( V_5 -> V_1 ) ;
#if 0
release_mem_region(dev->hpa, GSC_STATUS + 4);
#endif
F_24 ( & V_17 -> V_17 , NULL ) ;
F_36 ( V_5 ) ;
return 0 ;
}
static int T_5 F_41 ( void )
{
F_42 ( & V_64 ) ;
return 0 ;
}
static void T_6 F_43 ( void )
{
F_44 ( & V_64 ) ;
}
