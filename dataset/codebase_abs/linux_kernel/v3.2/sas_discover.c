void F_1 ( struct V_1 * V_2 )
{
F_2 ( & V_2 -> V_3 ) ;
F_2 ( & V_2 -> V_4 ) ;
switch ( V_2 -> V_5 ) {
case V_6 :
break;
case V_7 :
case V_8 :
F_2 ( & V_2 -> V_9 . V_10 ) ;
break;
case V_11 :
case V_12 :
case V_13 :
F_2 ( & V_2 -> V_14 . V_10 ) ;
break;
default:
break;
}
}
static int F_3 ( struct V_15 * V_16 )
{
unsigned long V_17 ;
struct V_18 * V_19 ;
struct V_20 * V_21 ;
struct V_1 * V_2 ;
V_2 = F_4 ( sizeof( * V_2 ) , V_22 ) ;
if ( ! V_2 )
return - V_23 ;
F_5 ( & V_16 -> V_24 , V_17 ) ;
if ( F_6 ( & V_16 -> V_25 ) ) {
F_7 ( & V_16 -> V_24 , V_17 ) ;
F_8 ( V_2 ) ;
return - V_26 ;
}
V_19 = F_9 ( V_16 -> V_25 . V_27 , struct V_18 , V_28 ) ;
F_10 ( & V_19 -> V_29 ) ;
memcpy ( V_2 -> V_30 , V_19 -> V_30 , F_11 ( sizeof( V_2 -> V_30 ) ,
( V_31 ) V_19 -> V_32 ) ) ;
F_12 ( & V_19 -> V_29 ) ;
F_7 ( & V_16 -> V_24 , V_17 ) ;
if ( V_2 -> V_30 [ 0 ] == 0x34 && V_16 -> V_33 == V_34 ) {
struct V_35 * V_36 =
(struct V_35 * ) V_2 -> V_30 ;
if ( V_36 -> V_37 == 1 && V_36 -> V_38 == 1 &&
V_36 -> V_39 == 0x69 && V_36 -> V_40 == 0x96
&& ( V_36 -> V_41 & ~ 0x10 ) == 0 )
V_2 -> V_5 = V_12 ;
else
V_2 -> V_5 = V_11 ;
V_2 -> V_42 = V_43 ;
} else {
struct V_44 * V_45 =
(struct V_44 * ) V_2 -> V_30 ;
V_2 -> V_5 = V_45 -> V_5 ;
V_2 -> V_46 = V_45 -> V_47 ;
V_2 -> V_42 = V_45 -> V_48 ;
}
F_1 ( V_2 ) ;
switch ( V_2 -> V_5 ) {
case V_6 :
case V_11 :
V_21 = F_13 ( V_16 -> V_16 ) ;
break;
case V_7 :
V_21 = F_14 ( V_16 -> V_16 ,
V_49 ) ;
break;
case V_8 :
V_21 = F_14 ( V_16 -> V_16 ,
V_50 ) ;
break;
default:
F_15 ( L_1 , V_2 -> V_5 ) ;
V_21 = NULL ;
break;
}
if ( ! V_21 ) {
F_8 ( V_2 ) ;
return - V_26 ;
}
V_21 -> V_51 . V_52 = V_19 -> V_19 -> V_51 . V_52 ;
memcpy ( V_2 -> V_53 , V_16 -> V_54 , V_55 ) ;
F_16 ( V_2 , V_21 ) ;
F_17 ( V_2 -> V_56 , V_2 -> V_53 ) ;
V_16 -> V_57 = V_2 ;
V_2 -> V_16 = V_16 ;
V_2 -> V_58 = V_16 -> V_58 ;
V_2 -> V_59 = V_16 -> V_58 ;
V_2 -> V_60 = V_16 -> V_58 ;
V_2 -> V_61 = V_16 -> V_62 ;
memset ( V_16 -> V_63 . V_64 , 0 , V_55 ) ;
memset ( V_16 -> V_63 . V_65 , 0 , V_55 ) ;
memset ( V_16 -> V_63 . V_66 , 0 , V_55 ) ;
V_16 -> V_63 . V_67 = 0 ;
V_2 -> V_21 = V_21 ;
F_18 ( & V_16 -> V_68 ) ;
F_19 ( & V_2 -> V_4 , & V_16 -> V_69 ) ;
F_20 ( & V_16 -> V_68 ) ;
return 0 ;
}
int F_21 ( struct V_1 * V_2 )
{
int V_70 = 0 ;
struct V_71 * V_72 = V_2 -> V_16 -> V_73 ;
struct V_74 * V_75 = V_72 -> V_76 . V_75 ;
struct V_77 * V_78 = F_22 ( V_75 -> V_79 ) ;
if ( V_78 -> V_80 -> V_81 ) {
V_70 = V_78 -> V_80 -> V_81 ( V_2 ) ;
if ( V_70 ) {
F_15 ( L_2
L_3 ,
F_23 ( V_72 -> V_2 ) ,
F_24 ( V_2 -> V_53 ) , V_70 ) ;
}
}
return V_70 ;
}
void F_25 ( struct V_1 * V_2 )
{
struct V_71 * V_72 = V_2 -> V_16 -> V_73 ;
struct V_74 * V_75 = V_72 -> V_76 . V_75 ;
struct V_77 * V_78 = F_22 ( V_75 -> V_79 ) ;
if ( V_78 -> V_80 -> V_82 )
V_78 -> V_80 -> V_82 ( V_2 ) ;
}
int F_26 ( struct V_1 * V_2 )
{
int V_70 ;
V_70 = F_21 ( V_2 ) ;
if ( V_70 )
goto V_83;
V_70 = F_27 ( V_2 -> V_21 ) ;
if ( V_70 )
goto V_84;
return 0 ;
V_84:
F_25 ( V_2 ) ;
V_83:
return V_70 ;
}
static void F_28 ( struct V_15 * V_16 , struct V_1 * V_2 )
{
F_25 ( V_2 ) ;
if ( ! V_2 -> V_85 )
V_2 -> V_16 -> V_57 = NULL ;
else
F_29 ( & V_2 -> V_3 ) ;
F_18 ( & V_16 -> V_68 ) ;
F_29 ( & V_2 -> V_4 ) ;
F_20 ( & V_16 -> V_68 ) ;
}
void F_30 ( struct V_15 * V_16 , struct V_1 * V_2 )
{
if ( V_2 -> V_21 ) {
F_31 ( & V_2 -> V_21 -> V_2 ) ;
F_32 ( V_2 -> V_21 ) ;
V_2 -> V_21 = NULL ;
}
if ( V_2 -> V_5 == V_7 || V_2 -> V_5 == V_8 ) {
F_8 ( V_2 -> V_9 . V_86 ) ;
V_2 -> V_9 . V_86 = NULL ;
}
F_28 ( V_16 , V_2 ) ;
}
void F_33 ( struct V_15 * V_16 )
{
struct V_1 * V_2 , * V_87 ;
F_34 (dev, n, &port->dev_list, dev_list_node)
F_30 ( V_16 , V_2 ) ;
V_16 -> V_16 -> V_21 = NULL ;
}
static void F_35 ( struct V_88 * V_89 )
{
struct V_1 * V_2 ;
int error = 0 ;
struct V_90 * V_91 =
F_9 ( V_89 , struct V_90 , V_89 ) ;
struct V_15 * V_16 = V_91 -> V_16 ;
F_36 ( V_92 , & V_16 -> V_63 . V_93 ,
& V_16 -> V_63 . V_94 ) ;
if ( V_16 -> V_57 )
return;
error = F_3 ( V_16 ) ;
if ( error )
return;
V_2 = V_16 -> V_57 ;
F_37 ( L_4 , V_16 -> V_45 ,
F_38 ( V_95 ) ) ;
switch ( V_2 -> V_5 ) {
case V_6 :
error = F_26 ( V_2 ) ;
break;
case V_7 :
case V_8 :
error = F_39 ( V_2 ) ;
break;
case V_11 :
case V_12 :
#ifdef F_40
error = F_41 ( V_2 ) ;
break;
#else
F_37 ( L_5 ) ;
#endif
default:
error = - V_96 ;
F_37 ( L_6 , V_2 -> V_5 ) ;
break;
}
if ( error ) {
F_42 ( V_2 -> V_21 ) ;
V_2 -> V_21 = NULL ;
F_18 ( & V_16 -> V_68 ) ;
F_29 ( & V_2 -> V_4 ) ;
F_20 ( & V_16 -> V_68 ) ;
F_8 ( V_2 ) ;
V_16 -> V_57 = NULL ;
}
F_37 ( L_7 , V_16 -> V_45 ,
F_38 ( V_95 ) , error ) ;
}
static void F_43 ( struct V_88 * V_89 )
{
int V_70 = 0 ;
struct V_90 * V_91 =
F_9 ( V_89 , struct V_90 , V_89 ) ;
struct V_15 * V_16 = V_91 -> V_16 ;
F_36 ( V_97 , & V_16 -> V_63 . V_93 ,
& V_16 -> V_63 . V_94 ) ;
F_37 ( L_8 , V_16 -> V_45 ,
F_38 ( V_95 ) ) ;
if ( V_16 -> V_57 )
V_70 = F_44 ( V_16 -> V_57 ) ;
F_37 ( L_9 ,
V_16 -> V_45 , F_38 ( V_95 ) , V_70 ) ;
}
int F_45 ( struct V_15 * V_16 , enum V_98 V_91 )
{
struct V_99 * V_63 ;
if ( ! V_16 )
return 0 ;
V_63 = & V_16 -> V_63 ;
F_46 ( V_91 >= V_100 ) ;
F_47 ( V_91 , & V_63 -> V_93 , & V_63 -> V_94 ,
& V_63 -> V_101 [ V_91 ] . V_89 , V_16 -> V_73 ) ;
return 0 ;
}
void F_48 ( struct V_99 * V_63 , struct V_15 * V_16 )
{
int V_78 ;
static const T_1 V_102 [ V_100 ] = {
[ V_92 ] = F_35 ,
[ V_97 ] = F_43 ,
} ;
F_49 ( & V_63 -> V_93 ) ;
V_63 -> V_94 = 0 ;
for ( V_78 = 0 ; V_78 < V_100 ; V_78 ++ ) {
F_50 ( & V_63 -> V_101 [ V_78 ] . V_89 , V_102 [ V_78 ] ) ;
V_63 -> V_101 [ V_78 ] . V_16 = V_16 ;
}
}
