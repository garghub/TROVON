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
if ( V_25 )
F_12 ( 5 ) ;
if ( F_1 ( V_2 , V_26 , & V_22 ) )
goto V_27;
if ( V_22 ) {
V_19 = - V_28 ;
goto V_27;
}
F_3 ( V_2 , V_29 , V_17 ) ;
if ( ! ( V_16 & 0x01 ) ) {
F_3 ( V_2 , V_30 , V_18 ) ;
for ( V_21 = 0 ; V_21 < V_18 ; ++ V_21 )
F_3 ( V_2 , V_31 + V_21 , V_4 [ V_21 ] ) ;
}
F_3 ( V_2 , V_32 , V_3 << 1 ) ;
F_3 ( V_2 , V_26 , V_16 ) ;
V_19 = F_6 ( V_2 , 1000 ) ;
if ( V_19 || ! ( V_16 & 0x01 ) )
goto V_27;
switch ( V_16 ) {
case V_33 :
case V_34 :
V_23 = 1 ;
break;
case V_35 :
V_23 = 2 ;
break;
case V_36 :
if ( F_1 ( V_2 , V_30 , & V_23 ) ) {
V_19 = - V_20 ;
goto V_27;
}
V_23 &= 0x1f ;
break;
}
for ( V_21 = 0 ; V_21 < V_23 ; ++ V_21 )
F_1 ( V_2 , V_31 + V_21 , & V_4 [ V_21 ] ) ;
V_27:
F_13 ( & V_2 -> V_24 ) ;
return V_19 ;
}
int F_14 ( struct V_1 * V_2 , T_1 V_16 , T_1 V_3 ,
T_1 V_17 , T_1 * V_4 )
{
return F_9 ( V_2 , V_16 , V_3 , V_17 , V_4 , 0 ) ;
}
int F_15 ( struct V_1 * V_2 , T_1 V_16 , T_1 V_3 ,
T_1 V_17 , T_1 * V_4 , T_1 V_18 )
{
return F_9 ( V_2 , V_16 , V_3 , V_17 , V_4 , V_18 ) ;
}
int F_16 ( struct V_1 * V_2 ,
T_2 V_37 , void * V_38 )
{
F_11 ( & V_2 -> V_24 ) ;
V_2 -> V_37 = V_37 ;
V_2 -> V_38 = V_38 ;
F_13 ( & V_2 -> V_24 ) ;
return 0 ;
}
int F_17 ( struct V_1 * V_2 )
{
F_11 ( & V_2 -> V_24 ) ;
V_2 -> V_37 = NULL ;
V_2 -> V_38 = NULL ;
F_13 ( & V_2 -> V_24 ) ;
return 0 ;
}
static inline void F_18 ( void * V_38 )
{
struct V_1 * V_2 = V_38 ;
if ( V_2 -> V_37 )
V_2 -> V_37 ( V_2 -> V_38 ) ;
}
static int F_19 ( void * V_38 )
{
struct V_1 * V_2 = V_38 ;
union V_6 V_7 ;
T_1 V_3 ;
if ( F_1 ( V_2 , V_9 , & V_7 . V_8 ) )
return 0 ;
if ( V_7 . V_10 . V_11 )
F_20 ( & V_2 -> V_14 ) ;
if ( ! V_7 . V_10 . V_39 )
return 0 ;
F_11 ( & V_2 -> V_24 ) ;
F_1 ( V_2 , V_40 , & V_3 ) ;
V_7 . V_10 . V_39 = 0 ;
F_3 ( V_2 , V_9 , V_7 . V_8 ) ;
switch ( V_3 >> 1 ) {
case V_41 :
case V_42 :
case V_43 :
F_21 ( V_44 ,
F_18 , V_2 ) ;
default: ;
}
F_13 ( & V_2 -> V_24 ) ;
return 0 ;
}
static int F_22 ( const struct V_45 * V_46 )
{
F_23 ( L_2 ) ;
V_25 = true ;
return 0 ;
}
static int F_24 ( struct V_47 * V_48 )
{
int V_7 ;
unsigned long long V_49 ;
struct V_1 * V_2 ;
F_25 ( V_50 ) ;
if ( ! V_48 )
return - V_51 ;
V_7 = F_26 ( V_48 -> V_52 , L_3 , NULL , & V_49 ) ;
if ( F_27 ( V_7 ) ) {
F_10 (KERN_ERR PREFIX L_4 ) ;
return - V_53 ;
}
strcpy ( F_28 ( V_48 ) , V_54 ) ;
strcpy ( F_29 ( V_48 ) , V_55 ) ;
V_2 = F_30 ( sizeof( struct V_1 ) , V_56 ) ;
if ( ! V_2 )
return - V_57 ;
F_31 ( & V_2 -> V_24 ) ;
F_32 ( & V_2 -> V_14 ) ;
V_2 -> V_58 = F_33 ( V_48 -> V_59 ) ;
V_2 -> V_5 = ( V_49 >> 8 ) & 0xff ;
V_2 -> V_60 = V_49 & 0xff ;
V_48 -> V_61 = V_2 ;
F_34 ( V_2 -> V_58 , V_2 -> V_60 , NULL , F_19 , V_2 ) ;
F_10 (KERN_INFO PREFIX L_5 ,
hc->ec, hc->offset, hc->query_bit) ;
return 0 ;
}
static int F_35 ( struct V_47 * V_48 )
{
struct V_1 * V_2 ;
if ( ! V_48 )
return - V_51 ;
V_2 = F_33 ( V_48 ) ;
F_36 ( V_2 -> V_58 , V_2 -> V_60 ) ;
F_37 ( V_2 ) ;
V_48 -> V_61 = NULL ;
return 0 ;
}
