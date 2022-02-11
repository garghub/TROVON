static inline void F_1 ( void )
{
F_2 ( V_1 , V_2 | V_3 ) ;
}
static void F_3 ( unsigned long V_4 )
{
if ( F_4 ( V_5 , V_6 . V_7 ) ||
( ! V_8 && ! V_6 . V_9 ) ) {
F_1 () ;
F_5 ( & V_6 . V_10 , V_5 + V_11 ) ;
} else
F_6 (KERN_CRIT DRV_NAMEL_1 ) ;
}
static int F_7 ( struct V_12 * V_12 , struct V_13 * V_13 )
{
if ( F_8 ( 0 , & V_6 . V_9 ) )
return - V_14 ;
V_6 . V_7 = V_5 + V_15 * V_16 ;
F_5 ( & V_6 . V_10 , V_5 + V_11 ) ;
return F_9 ( V_12 , V_13 ) ;
}
static int F_10 ( struct V_12 * V_12 , struct V_13 * V_13 )
{
F_11 ( 0 , & V_6 . V_9 ) ;
if ( ! V_6 . V_17 )
F_12 ( & V_6 . V_10 ) ;
V_6 . V_17 = 0 ;
return 0 ;
}
static int F_13 ( unsigned int V_18 )
{
unsigned int V_19 ;
unsigned int V_20 ;
V_20 = F_14 ( V_21 ) ;
if ( V_20 & V_22 ) {
F_6 (KERN_ERR DRV_NAMEL_2 ) ;
return - V_23 ;
}
V_19 = V_24
| V_25
| V_26
| ( V_18 & V_27 ) ;
F_2 ( V_21 , V_19 ) ;
return 0 ;
}
static long F_15 ( struct V_13 * V_13 ,
unsigned int V_28 , unsigned long V_29 )
{
void T_1 * V_30 = ( void T_1 * ) V_29 ;
int T_1 * V_31 = V_30 ;
int V_32 ;
switch ( V_28 ) {
case V_33 :
return F_16 ( V_30 , & V_34 ,
sizeof( V_34 ) ) ? - V_35 : 0 ;
case V_36 :
case V_37 :
return F_17 ( 0 , V_31 ) ;
case V_38 :
V_6 . V_7 = V_5 + V_15 * V_16 ;
return 0 ;
case V_39 :
if ( F_18 ( V_32 , V_31 ) )
return - V_35 ;
V_15 = V_32 ;
V_6 . V_7 = V_5 + V_15 * V_16 ;
return F_17 ( V_32 , V_31 ) ;
case V_40 :
return F_17 ( V_15 , V_31 ) ;
}
return - V_41 ;
}
static T_2 F_19 ( struct V_13 * V_13 , const char * V_4 , T_3 V_42 ,
T_4 * V_43 )
{
if ( ! V_42 )
return 0 ;
if ( ! V_8 ) {
T_3 V_44 ;
V_6 . V_17 = 0 ;
for ( V_44 = 0 ; V_44 < V_42 ; V_44 ++ ) {
char V_45 ;
if ( F_18 ( V_45 , V_4 + V_44 ) )
return - V_35 ;
if ( V_45 == 'V' ) {
V_6 . V_17 = 42 ;
break;
}
}
}
V_6 . V_7 = V_5 + V_15 * V_16 ;
return V_42 ;
}
static int T_5 F_20 ( struct V_46 * V_47 )
{
int V_48 ;
if ( V_49 . V_50 )
return - V_14 ;
V_49 . V_50 = & V_47 -> V_51 ;
V_48 = F_13 ( F_21 ( V_52 * 1000 ) ) ;
if ( V_48 )
return V_48 ;
V_48 = F_22 ( & V_49 ) ;
if ( V_48 )
return V_48 ;
V_6 . V_7 = V_5 + V_15 * V_16 ;
F_23 ( & V_6 . V_10 , F_3 , 0 ) ;
F_5 ( & V_6 . V_10 , V_5 + V_11 ) ;
F_6 (KERN_INFO DRV_NAME L_3 ,
heartbeat, nowayout) ;
return 0 ;
}
static int T_6 F_24 ( struct V_46 * V_47 )
{
int V_48 ;
V_48 = F_25 ( & V_49 ) ;
if ( ! V_48 )
V_49 . V_50 = NULL ;
return V_48 ;
}
static int F_26 ( struct V_46 * V_47 , T_7 V_53 )
{
return 0 ;
}
static int F_27 ( struct V_46 * V_47 )
{
return 0 ;
}
static int T_5 F_28 ( void )
{
return F_29 ( & V_54 , F_20 ) ;
}
static void T_6 F_30 ( void )
{
F_31 ( & V_54 ) ;
}
