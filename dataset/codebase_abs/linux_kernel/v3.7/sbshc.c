static inline int F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 * V_4 )
{
return F_2 ( V_2 -> V_5 + V_3 , V_4 ) ;
}
static inline int F_3 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 )
{
return F_4 ( V_2 -> V_5 + V_3 , V_4 ) ;
}
static inline int F_5 ( struct V_1 * V_2 )
{
union V_6 V_7 = { . V_8 = 0 } ;
F_1 ( V_2 , V_9 , & V_7 . V_8 ) ;
return V_7 . V_10 . V_11 && ( V_7 . V_10 . V_7 == V_12 ) ;
}
static int F_6 ( struct V_1 * V_2 , int V_13 )
{
if ( F_7 ( V_2 -> V_14 , F_5 ( V_2 ) ,
F_8 ( V_13 ) ) )
return 0 ;
if ( F_5 ( V_2 ) )
return 0 ;
else
return - V_15 ;
}
static int F_9 ( struct V_1 * V_2 , T_1 V_16 ,
T_1 V_3 , T_1 V_17 , T_1 * V_4 , T_1 V_18 )
{
int V_19 = - V_20 , V_21 ;
T_1 V_22 , V_23 = 0 ;
if ( ! V_2 ) {
F_10 (KERN_ERR PREFIX L_1 ) ;
return V_19 ;
}
F_11 ( & V_2 -> V_24 ) ;
if ( F_1 ( V_2 , V_25 , & V_22 ) )
goto V_26;
if ( V_22 ) {
V_19 = - V_27 ;
goto V_26;
}
F_3 ( V_2 , V_28 , V_17 ) ;
if ( ! ( V_16 & 0x01 ) ) {
F_3 ( V_2 , V_29 , V_18 ) ;
for ( V_21 = 0 ; V_21 < V_18 ; ++ V_21 )
F_3 ( V_2 , V_30 + V_21 , V_4 [ V_21 ] ) ;
}
F_3 ( V_2 , V_31 , V_3 << 1 ) ;
F_3 ( V_2 , V_25 , V_16 ) ;
V_19 = F_6 ( V_2 , 1000 ) ;
if ( V_19 || ! ( V_16 & 0x01 ) )
goto V_26;
switch ( V_16 ) {
case V_32 :
case V_33 :
V_23 = 1 ;
break;
case V_34 :
V_23 = 2 ;
break;
case V_35 :
if ( F_1 ( V_2 , V_29 , & V_23 ) ) {
V_19 = - V_20 ;
goto V_26;
}
V_23 &= 0x1f ;
break;
}
for ( V_21 = 0 ; V_21 < V_23 ; ++ V_21 )
F_1 ( V_2 , V_30 + V_21 , & V_4 [ V_21 ] ) ;
V_26:
F_12 ( & V_2 -> V_24 ) ;
return V_19 ;
}
int F_13 ( struct V_1 * V_2 , T_1 V_16 , T_1 V_3 ,
T_1 V_17 , T_1 * V_4 )
{
return F_9 ( V_2 , V_16 , V_3 , V_17 , V_4 , 0 ) ;
}
int F_14 ( struct V_1 * V_2 , T_1 V_16 , T_1 V_3 ,
T_1 V_17 , T_1 * V_4 , T_1 V_18 )
{
return F_9 ( V_2 , V_16 , V_3 , V_17 , V_4 , V_18 ) ;
}
int F_15 ( struct V_1 * V_2 ,
T_2 V_36 , void * V_37 )
{
F_11 ( & V_2 -> V_24 ) ;
V_2 -> V_36 = V_36 ;
V_2 -> V_37 = V_37 ;
F_12 ( & V_2 -> V_24 ) ;
return 0 ;
}
int F_16 ( struct V_1 * V_2 )
{
F_11 ( & V_2 -> V_24 ) ;
V_2 -> V_36 = NULL ;
V_2 -> V_37 = NULL ;
F_12 ( & V_2 -> V_24 ) ;
return 0 ;
}
static inline void F_17 ( void * V_37 )
{
struct V_1 * V_2 = V_37 ;
if ( V_2 -> V_36 )
V_2 -> V_36 ( V_2 -> V_37 ) ;
}
static int F_18 ( void * V_37 )
{
struct V_1 * V_2 = V_37 ;
union V_6 V_7 ;
T_1 V_3 ;
if ( F_1 ( V_2 , V_9 , & V_7 . V_8 ) )
return 0 ;
if ( V_7 . V_10 . V_11 )
F_19 ( & V_2 -> V_14 ) ;
if ( ! V_7 . V_10 . V_38 )
return 0 ;
F_11 ( & V_2 -> V_24 ) ;
F_1 ( V_2 , V_39 , & V_3 ) ;
V_7 . V_10 . V_38 = 0 ;
F_3 ( V_2 , V_9 , V_7 . V_8 ) ;
switch ( V_3 >> 1 ) {
case V_40 :
case V_41 :
case V_42 :
F_20 ( V_43 ,
F_17 , V_2 ) ;
default: ;
}
F_12 ( & V_2 -> V_24 ) ;
return 0 ;
}
static int F_21 ( struct V_44 * V_45 )
{
int V_7 ;
unsigned long long V_46 ;
struct V_1 * V_2 ;
if ( ! V_45 )
return - V_47 ;
V_7 = F_22 ( V_45 -> V_48 , L_2 , NULL , & V_46 ) ;
if ( F_23 ( V_7 ) ) {
F_10 (KERN_ERR PREFIX L_3 ) ;
return - V_49 ;
}
strcpy ( F_24 ( V_45 ) , V_50 ) ;
strcpy ( F_25 ( V_45 ) , V_51 ) ;
V_2 = F_26 ( sizeof( struct V_1 ) , V_52 ) ;
if ( ! V_2 )
return - V_53 ;
F_27 ( & V_2 -> V_24 ) ;
F_28 ( & V_2 -> V_14 ) ;
V_2 -> V_54 = F_29 ( V_45 -> V_55 ) ;
V_2 -> V_5 = ( V_46 >> 8 ) & 0xff ;
V_2 -> V_56 = V_46 & 0xff ;
V_45 -> V_57 = V_2 ;
F_30 ( V_2 -> V_54 , V_2 -> V_56 , NULL , F_18 , V_2 ) ;
F_10 (KERN_INFO PREFIX L_4 ,
hc->ec, hc->offset, hc->query_bit) ;
return 0 ;
}
static int F_31 ( struct V_44 * V_45 , int type )
{
struct V_1 * V_2 ;
if ( ! V_45 )
return - V_47 ;
V_2 = F_29 ( V_45 ) ;
F_32 ( V_2 -> V_54 , V_2 -> V_56 ) ;
F_33 ( V_2 ) ;
V_45 -> V_57 = NULL ;
return 0 ;
}
