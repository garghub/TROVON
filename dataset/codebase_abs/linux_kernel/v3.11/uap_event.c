struct V_1 *
F_1 ( struct V_2 * V_3 , T_1 * V_4 )
{
struct V_1 * V_5 ;
if ( ! V_4 )
return NULL ;
F_2 (node, &priv->sta_list, list) {
if ( ! memcmp ( V_5 -> V_6 , V_4 , V_7 ) )
return V_5 ;
}
return NULL ;
}
static struct V_1 *
F_3 ( struct V_2 * V_3 , T_1 * V_4 )
{
struct V_1 * V_5 ;
unsigned long V_8 ;
if ( ! V_4 )
return NULL ;
F_4 ( & V_3 -> V_9 , V_8 ) ;
V_5 = F_1 ( V_3 , V_4 ) ;
if ( V_5 )
goto V_10;
V_5 = F_5 ( sizeof( struct V_1 ) , V_11 ) ;
if ( ! V_5 )
goto V_10;
memcpy ( V_5 -> V_6 , V_4 , V_7 ) ;
F_6 ( & V_5 -> V_12 , & V_3 -> V_13 ) ;
V_10:
F_7 ( & V_3 -> V_9 , V_8 ) ;
return V_5 ;
}
static void
F_8 ( struct V_2 * V_3 , const T_1 * V_14 ,
int V_15 , struct V_1 * V_5 )
{
const struct V_16 * V_17 ;
if ( ! V_14 )
return;
V_17 = ( void * ) F_9 ( V_18 , V_14 , V_15 ) ;
if ( V_17 ) {
V_5 -> V_19 = 1 ;
V_5 -> V_20 = F_10 ( V_17 -> V_21 ) &
V_22 ?
V_23 :
V_24 ;
} else {
V_5 -> V_19 = 0 ;
}
return;
}
static void F_11 ( struct V_2 * V_3 , T_1 * V_4 )
{
struct V_1 * V_5 ;
unsigned long V_8 ;
F_4 ( & V_3 -> V_9 , V_8 ) ;
V_5 = F_1 ( V_3 , V_4 ) ;
if ( V_5 ) {
F_12 ( & V_5 -> V_12 ) ;
F_13 ( V_5 ) ;
}
F_7 ( & V_3 -> V_9 , V_8 ) ;
return;
}
static void F_14 ( struct V_2 * V_3 )
{
struct V_1 * V_5 , * V_25 ;
unsigned long V_8 ;
F_4 ( & V_3 -> V_9 , V_8 ) ;
F_15 (node, tmp, &priv->sta_list, list) {
F_12 ( & V_5 -> V_12 ) ;
F_13 ( V_5 ) ;
}
F_16 ( & V_3 -> V_13 ) ;
F_7 ( & V_3 -> V_9 , V_8 ) ;
return;
}
int F_17 ( struct V_2 * V_3 )
{
struct V_26 * V_27 = V_3 -> V_27 ;
int V_28 , V_29 ;
T_2 V_30 = V_27 -> V_31 ;
struct V_32 V_33 ;
struct V_34 * V_35 ;
struct V_1 * V_5 ;
T_1 * V_36 ;
struct V_37 * V_38 ;
T_3 V_39 ;
switch ( V_30 ) {
case V_40 :
memset ( & V_33 , 0 , sizeof( V_33 ) ) ;
V_35 = (struct V_34 * )
( V_27 -> V_41 + V_42 ) ;
if ( F_10 ( V_35 -> type ) == V_43 ) {
V_28 = - 1 ;
if ( F_18 ( V_35 -> V_44 ) )
V_28 = 0 ;
else if ( F_19 ( V_35 -> V_44 ) )
V_28 = V_7 ;
if ( V_28 != - 1 ) {
V_33 . V_45 = V_46 ;
V_33 . V_47 = & V_35 -> V_48 [ V_28 ] ;
V_28 = ( T_1 * ) V_33 . V_47 -
( T_1 * ) & V_35 -> V_44 ;
V_33 . V_49 =
F_10 ( V_35 -> V_28 ) - ( T_3 ) V_28 ;
}
}
F_20 ( V_3 -> V_50 , V_35 -> V_51 , & V_33 ,
V_52 ) ;
V_5 = F_3 ( V_3 , V_35 -> V_51 ) ;
if ( ! V_5 ) {
F_21 ( V_27 -> V_53 ,
L_1 ) ;
return - 1 ;
}
if ( ! V_3 -> V_54 )
break;
F_8 ( V_3 , V_33 . V_47 ,
V_33 . V_49 , V_5 ) ;
for ( V_29 = 0 ; V_29 < V_55 ; V_29 ++ ) {
if ( V_5 -> V_19 )
V_5 -> V_56 [ V_29 ] =
V_3 -> V_57 [ V_29 ] . V_58 ;
else
V_5 -> V_56 [ V_29 ] = V_59 ;
}
memset ( V_5 -> V_60 , 0xff , sizeof( V_5 -> V_60 ) ) ;
break;
case V_61 :
V_36 = V_27 -> V_41 +
V_42 ;
F_22 ( V_3 -> V_50 , V_36 , V_52 ) ;
if ( V_3 -> V_54 ) {
F_23 ( V_3 , V_36 ) ;
F_24 ( V_3 , V_36 ) ;
}
F_11 ( V_3 , V_36 ) ;
break;
case V_62 :
V_3 -> V_63 = false ;
if ( F_25 ( V_3 -> V_50 ) )
F_26 ( V_3 -> V_50 ) ;
F_27 ( V_3 -> V_50 , V_27 ) ;
F_28 ( V_3 ) ;
F_14 ( V_3 ) ;
break;
case V_64 :
V_3 -> V_63 = true ;
if ( ! F_25 ( V_3 -> V_50 ) )
F_29 ( V_3 -> V_50 ) ;
F_30 ( V_3 -> V_50 , V_27 ) ;
break;
case V_65 :
F_31 ( V_27 -> V_53 , L_2 , V_30 ) ;
memcpy ( V_3 -> V_50 -> V_66 , V_27 -> V_41 + 2 ,
V_7 ) ;
break;
case V_67 :
F_31 ( V_27 -> V_53 , L_2 , V_30 ) ;
break;
case V_68 :
V_39 = F_10 ( * ( V_69 * ) V_27 -> V_41 ) ;
F_31 ( V_27 -> V_53 , L_3 , V_39 ) ;
if ( V_3 -> V_63 ) {
V_27 -> V_70 =
F_32 ( T_3 , V_27 -> V_71 , V_39 ) ;
F_31 ( V_27 -> V_53 , L_4 ,
V_27 -> V_70 ) ;
}
break;
case V_72 :
F_31 ( V_27 -> V_53 , L_5 ) ;
if ( V_3 -> V_63 )
F_33 ( V_3 , V_73 ,
V_74 , 0 ,
V_27 -> V_41 ) ;
break;
case V_75 :
F_31 ( V_27 -> V_53 , L_6 ) ;
if ( V_3 -> V_63 )
F_34 ( V_3 , V_27 -> V_41 ) ;
break;
case V_76 :
F_31 ( V_27 -> V_53 , L_7 ) ;
if ( V_3 -> V_63 ) {
V_38 = ( void * ) V_27 -> V_41 ;
F_35 ( V_3 , V_38 ) ;
}
break;
default:
F_31 ( V_27 -> V_53 , L_8 ,
V_30 ) ;
break;
}
return 0 ;
}
void F_36 ( struct V_2 * V_3 ,
struct V_1 * V_5 )
{
if ( V_3 -> V_54 && V_5 -> V_19 ) {
F_23 ( V_3 , V_5 -> V_6 ) ;
F_24 ( V_3 , V_5 -> V_6 ) ;
}
F_11 ( V_3 , V_5 -> V_6 ) ;
return;
}
