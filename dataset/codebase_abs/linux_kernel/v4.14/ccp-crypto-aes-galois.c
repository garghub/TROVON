static int F_1 ( struct V_1 * V_2 , int V_3 )
{
return V_3 ;
}
static int F_2 ( struct V_4 * V_5 , const T_1 * V_6 ,
unsigned int V_7 )
{
struct V_8 * V_9 = F_3 ( V_5 ) ;
switch ( V_7 ) {
case V_10 :
V_9 -> V_11 . V_12 . type = V_13 ;
break;
case V_14 :
V_9 -> V_11 . V_12 . type = V_15 ;
break;
case V_16 :
V_9 -> V_11 . V_12 . type = V_17 ;
break;
default:
F_4 ( V_5 , V_18 ) ;
return - V_19 ;
}
V_9 -> V_11 . V_12 . V_20 = V_21 ;
V_9 -> V_11 . V_12 . V_7 = V_7 ;
memcpy ( V_9 -> V_11 . V_12 . V_6 , V_6 , V_7 ) ;
F_5 ( & V_9 -> V_11 . V_12 . V_22 , V_9 -> V_11 . V_12 . V_6 , V_7 ) ;
return 0 ;
}
static int F_6 ( struct V_4 * V_5 ,
unsigned int V_23 )
{
return 0 ;
}
static int F_7 ( struct V_24 * V_25 , bool V_26 )
{
struct V_4 * V_5 = F_8 ( V_25 ) ;
struct V_8 * V_9 = F_3 ( V_5 ) ;
struct V_27 * V_28 = F_9 ( V_25 ) ;
struct V_29 * V_30 = NULL ;
unsigned int V_31 = 0 ;
int V_32 ;
int V_3 = 0 ;
if ( ! V_9 -> V_11 . V_12 . V_7 )
return - V_19 ;
if ( V_9 -> V_11 . V_12 . V_20 != V_21 )
return - V_19 ;
if ( ! V_25 -> V_33 )
return - V_19 ;
memcpy ( V_28 -> V_33 , V_25 -> V_33 , V_34 ) ;
for ( V_32 = 0 ; V_32 < 3 ; V_32 ++ )
V_28 -> V_33 [ V_32 + V_34 ] = 0 ;
V_28 -> V_33 [ V_35 - 1 ] = 1 ;
V_30 = & V_28 -> V_30 ;
V_31 = V_35 ;
F_5 ( V_30 , V_28 -> V_33 , V_31 ) ;
memset ( & V_28 -> V_36 , 0 , sizeof( V_28 -> V_36 ) ) ;
F_10 ( & V_28 -> V_36 . V_37 ) ;
V_28 -> V_36 . V_38 = V_39 ;
V_28 -> V_36 . V_11 . V_12 . type = V_9 -> V_11 . V_12 . type ;
V_28 -> V_36 . V_11 . V_12 . V_20 = V_9 -> V_11 . V_12 . V_20 ;
V_28 -> V_36 . V_11 . V_12 . V_40 = V_26 ;
V_28 -> V_36 . V_11 . V_12 . V_6 = & V_9 -> V_11 . V_12 . V_22 ;
V_28 -> V_36 . V_11 . V_12 . V_7 = V_9 -> V_11 . V_12 . V_7 ;
V_28 -> V_36 . V_11 . V_12 . V_33 = V_30 ;
V_28 -> V_36 . V_11 . V_12 . V_31 = V_31 ;
V_28 -> V_36 . V_11 . V_12 . V_41 = V_25 -> V_41 ;
V_28 -> V_36 . V_11 . V_12 . V_42 = V_25 -> V_43 ;
V_28 -> V_36 . V_11 . V_12 . V_44 = V_25 -> V_45 ;
V_28 -> V_36 . V_11 . V_12 . V_46 = V_25 -> V_46 ;
V_3 = F_11 ( & V_25 -> V_47 , & V_28 -> V_36 ) ;
return V_3 ;
}
static int F_12 ( struct V_24 * V_25 )
{
return F_7 ( V_25 , V_48 ) ;
}
static int F_13 ( struct V_24 * V_25 )
{
return F_7 ( V_25 , V_49 ) ;
}
static int F_14 ( struct V_4 * V_5 )
{
struct V_8 * V_9 = F_3 ( V_5 ) ;
V_9 -> V_50 = F_1 ;
V_9 -> V_11 . V_12 . V_7 = 0 ;
F_15 ( V_5 , sizeof( struct V_27 ) ) ;
return 0 ;
}
static void F_16 ( struct V_51 * V_5 )
{
}
static int F_17 ( struct V_52 * V_53 ,
const struct V_54 * V_55 )
{
struct V_56 * V_57 ;
struct V_58 * V_59 ;
int V_3 ;
V_57 = F_18 ( sizeof( * V_57 ) , V_60 ) ;
if ( ! V_57 )
return - V_61 ;
F_10 ( & V_57 -> V_37 ) ;
V_57 -> V_20 = V_55 -> V_20 ;
V_59 = & V_57 -> V_59 ;
* V_59 = * V_55 -> V_62 ;
snprintf ( V_59 -> V_47 . V_63 , V_64 , L_1 , V_55 -> V_65 ) ;
snprintf ( V_59 -> V_47 . V_66 , V_64 , L_1 ,
V_55 -> V_67 ) ;
V_59 -> V_47 . V_68 = V_55 -> V_69 ;
V_59 -> V_47 . V_70 . V_71 = V_55 -> V_71 ;
V_3 = F_19 ( V_59 ) ;
if ( V_3 ) {
F_20 ( L_2 ,
V_59 -> V_47 . V_63 , V_3 ) ;
F_21 ( V_57 ) ;
return V_3 ;
}
F_22 ( & V_57 -> V_37 , V_53 ) ;
return 0 ;
}
int F_23 ( struct V_52 * V_53 )
{
int V_32 , V_3 ;
unsigned int V_72 = F_24 () ;
for ( V_32 = 0 ; V_32 < F_25 ( V_73 ) ; V_32 ++ ) {
if ( V_73 [ V_32 ] . V_74 > V_72 )
continue;
V_3 = F_17 ( V_53 , & V_73 [ V_32 ] ) ;
if ( V_3 )
return V_3 ;
}
return 0 ;
}
