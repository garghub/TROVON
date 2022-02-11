static inline int F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 * V_4 )
{
return F_2 ( V_2 -> V_5 + V_3 , V_4 ) ;
}
static inline int F_3 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 )
{
return F_4 ( V_2 -> V_5 + V_3 , V_4 ) ;
}
static int F_5 ( struct V_1 * V_2 , int V_6 )
{
if ( F_6 ( V_2 -> V_7 , V_2 -> V_8 , F_7 ( V_6 ) ) )
return 0 ;
return - V_9 ;
}
static int F_8 ( struct V_1 * V_2 , T_1 V_10 ,
T_1 V_3 , T_1 V_11 , T_1 * V_4 , T_1 V_12 )
{
int V_13 = - V_14 , V_15 ;
T_1 V_16 , V_17 = 0 ;
if ( ! V_2 ) {
F_9 (KERN_ERR PREFIX L_1 ) ;
return V_13 ;
}
F_10 ( & V_2 -> V_18 ) ;
V_2 -> V_8 = false ;
if ( F_1 ( V_2 , V_19 , & V_16 ) )
goto V_20;
if ( V_16 ) {
V_13 = - V_21 ;
goto V_20;
}
F_3 ( V_2 , V_22 , V_11 ) ;
if ( ! ( V_10 & 0x01 ) ) {
F_3 ( V_2 , V_23 , V_12 ) ;
for ( V_15 = 0 ; V_15 < V_12 ; ++ V_15 )
F_3 ( V_2 , V_24 + V_15 , V_4 [ V_15 ] ) ;
}
F_3 ( V_2 , V_25 , V_3 << 1 ) ;
F_3 ( V_2 , V_19 , V_10 ) ;
V_13 = F_5 ( V_2 , 1000 ) ;
if ( V_13 || ! ( V_10 & 0x01 ) )
goto V_20;
switch ( V_10 ) {
case V_26 :
case V_27 :
V_17 = 1 ;
break;
case V_28 :
V_17 = 2 ;
break;
case V_29 :
if ( F_1 ( V_2 , V_23 , & V_17 ) ) {
V_13 = - V_14 ;
goto V_20;
}
V_17 &= 0x1f ;
break;
}
for ( V_15 = 0 ; V_15 < V_17 ; ++ V_15 )
F_1 ( V_2 , V_24 + V_15 , & V_4 [ V_15 ] ) ;
V_20:
F_11 ( & V_2 -> V_18 ) ;
return V_13 ;
}
int F_12 ( struct V_1 * V_2 , T_1 V_10 , T_1 V_3 ,
T_1 V_11 , T_1 * V_4 )
{
return F_8 ( V_2 , V_10 , V_3 , V_11 , V_4 , 0 ) ;
}
int F_13 ( struct V_1 * V_2 , T_1 V_10 , T_1 V_3 ,
T_1 V_11 , T_1 * V_4 , T_1 V_12 )
{
return F_8 ( V_2 , V_10 , V_3 , V_11 , V_4 , V_12 ) ;
}
int F_14 ( struct V_1 * V_2 ,
T_2 V_30 , void * V_31 )
{
F_10 ( & V_2 -> V_18 ) ;
V_2 -> V_30 = V_30 ;
V_2 -> V_31 = V_31 ;
F_11 ( & V_2 -> V_18 ) ;
return 0 ;
}
int F_15 ( struct V_1 * V_2 )
{
F_10 ( & V_2 -> V_18 ) ;
V_2 -> V_30 = NULL ;
V_2 -> V_31 = NULL ;
F_11 ( & V_2 -> V_18 ) ;
return 0 ;
}
static inline void F_16 ( void * V_31 )
{
struct V_1 * V_2 = V_31 ;
if ( V_2 -> V_30 )
V_2 -> V_30 ( V_2 -> V_31 ) ;
}
static int F_17 ( void * V_31 )
{
struct V_1 * V_2 = V_31 ;
union V_32 V_33 ;
T_1 V_3 ;
if ( F_1 ( V_2 , V_34 , & V_33 . V_35 ) )
return 0 ;
if ( V_33 . V_36 . V_8 && V_33 . V_36 . V_33 == V_37 ) {
V_2 -> V_8 = true ;
F_18 ( & V_2 -> V_7 ) ;
}
if ( ! V_33 . V_36 . V_38 )
return 0 ;
F_10 ( & V_2 -> V_18 ) ;
F_1 ( V_2 , V_39 , & V_3 ) ;
V_33 . V_36 . V_38 = 0 ;
F_3 ( V_2 , V_34 , V_33 . V_35 ) ;
switch ( V_3 >> 1 ) {
case V_40 :
case V_41 :
case V_42 :
F_19 ( V_43 ,
F_16 , V_2 ) ;
default: ;
}
F_11 ( & V_2 -> V_18 ) ;
return 0 ;
}
static int F_20 ( struct V_44 * V_45 )
{
int V_33 ;
unsigned long long V_46 ;
struct V_1 * V_2 ;
if ( ! V_45 )
return - V_47 ;
V_33 = F_21 ( V_45 -> V_48 , L_2 , NULL , & V_46 ) ;
if ( F_22 ( V_33 ) ) {
F_9 (KERN_ERR PREFIX L_3 ) ;
return - V_49 ;
}
strcpy ( F_23 ( V_45 ) , V_50 ) ;
strcpy ( F_24 ( V_45 ) , V_51 ) ;
V_2 = F_25 ( sizeof( struct V_1 ) , V_52 ) ;
if ( ! V_2 )
return - V_53 ;
F_26 ( & V_2 -> V_18 ) ;
F_27 ( & V_2 -> V_7 ) ;
V_2 -> V_54 = F_28 ( V_45 -> V_55 ) ;
V_2 -> V_5 = ( V_46 >> 8 ) & 0xff ;
V_2 -> V_56 = V_46 & 0xff ;
V_45 -> V_57 = V_2 ;
F_29 ( V_2 -> V_54 , V_2 -> V_56 , NULL , F_17 , V_2 ) ;
F_9 (KERN_INFO PREFIX L_4 ,
hc->ec, hc->offset, hc->query_bit) ;
return 0 ;
}
static int F_30 ( struct V_44 * V_45 )
{
struct V_1 * V_2 ;
if ( ! V_45 )
return - V_47 ;
V_2 = F_28 ( V_45 ) ;
F_31 ( V_2 -> V_54 , V_2 -> V_56 ) ;
F_32 ( V_2 ) ;
V_45 -> V_57 = NULL ;
return 0 ;
}
