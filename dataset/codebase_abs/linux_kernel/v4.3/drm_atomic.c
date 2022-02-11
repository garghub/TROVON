void F_1 ( struct V_1 * V_2 )
{
F_2 ( V_2 -> V_3 ) ;
F_2 ( V_2 -> V_4 ) ;
F_2 ( V_2 -> V_5 ) ;
F_2 ( V_2 -> V_6 ) ;
F_2 ( V_2 -> V_7 ) ;
F_2 ( V_2 -> V_8 ) ;
}
int
F_3 ( struct V_9 * V_10 , struct V_1 * V_2 )
{
V_2 -> V_11 = true ;
V_2 -> V_12 = F_4 ( V_10 -> V_13 . V_12 ) ;
V_2 -> V_5 = F_5 ( V_10 -> V_13 . V_14 ,
sizeof( * V_2 -> V_5 ) , V_15 ) ;
if ( ! V_2 -> V_5 )
goto V_16;
V_2 -> V_6 = F_5 ( V_10 -> V_13 . V_14 ,
sizeof( * V_2 -> V_6 ) , V_15 ) ;
if ( ! V_2 -> V_6 )
goto V_16;
V_2 -> V_7 = F_5 ( V_10 -> V_13 . V_17 ,
sizeof( * V_2 -> V_7 ) , V_15 ) ;
if ( ! V_2 -> V_7 )
goto V_16;
V_2 -> V_8 = F_5 ( V_10 -> V_13 . V_17 ,
sizeof( * V_2 -> V_8 ) , V_15 ) ;
if ( ! V_2 -> V_8 )
goto V_16;
V_2 -> V_3 = F_5 ( V_2 -> V_12 ,
sizeof( * V_2 -> V_3 ) ,
V_15 ) ;
if ( ! V_2 -> V_3 )
goto V_16;
V_2 -> V_4 = F_5 ( V_2 -> V_12 ,
sizeof( * V_2 -> V_4 ) ,
V_15 ) ;
if ( ! V_2 -> V_4 )
goto V_16;
V_2 -> V_10 = V_10 ;
F_6 ( L_1 , V_2 ) ;
return 0 ;
V_16:
F_1 ( V_2 ) ;
return - V_18 ;
}
struct V_1 *
F_7 ( struct V_9 * V_10 )
{
struct V_19 * V_20 = & V_10 -> V_13 ;
struct V_1 * V_2 ;
if ( ! V_20 -> V_21 -> V_22 ) {
V_2 = F_8 ( sizeof( * V_2 ) , V_15 ) ;
if ( ! V_2 )
return NULL ;
if ( F_3 ( V_10 , V_2 ) < 0 ) {
F_2 ( V_2 ) ;
return NULL ;
}
return V_2 ;
}
return V_20 -> V_21 -> V_22 ( V_10 ) ;
}
void F_9 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = V_2 -> V_10 ;
struct V_19 * V_20 = & V_10 -> V_13 ;
int V_23 ;
F_6 ( L_2 , V_2 ) ;
for ( V_23 = 0 ; V_23 < V_2 -> V_12 ; V_23 ++ ) {
struct V_24 * V_25 = V_2 -> V_3 [ V_23 ] ;
if ( ! V_25 )
continue;
V_2 -> V_4 [ V_23 ] -> V_25 = NULL ;
V_25 -> V_21 -> V_26 ( NULL ,
V_2 -> V_4 [ V_23 ] ) ;
V_2 -> V_3 [ V_23 ] = NULL ;
V_2 -> V_4 [ V_23 ] = NULL ;
}
for ( V_23 = 0 ; V_23 < V_20 -> V_14 ; V_23 ++ ) {
struct V_27 * V_28 = V_2 -> V_5 [ V_23 ] ;
if ( ! V_28 )
continue;
V_28 -> V_21 -> V_26 ( V_28 ,
V_2 -> V_6 [ V_23 ] ) ;
V_2 -> V_5 [ V_23 ] = NULL ;
V_2 -> V_6 [ V_23 ] = NULL ;
}
for ( V_23 = 0 ; V_23 < V_20 -> V_17 ; V_23 ++ ) {
struct V_29 * V_30 = V_2 -> V_7 [ V_23 ] ;
if ( ! V_30 )
continue;
V_30 -> V_21 -> V_26 ( V_30 ,
V_2 -> V_8 [ V_23 ] ) ;
V_2 -> V_7 [ V_23 ] = NULL ;
V_2 -> V_8 [ V_23 ] = NULL ;
}
}
void F_10 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = V_2 -> V_10 ;
struct V_19 * V_20 = & V_10 -> V_13 ;
if ( V_20 -> V_21 -> V_31 )
V_20 -> V_21 -> V_31 ( V_2 ) ;
else
F_9 ( V_2 ) ;
}
void F_11 ( struct V_1 * V_2 )
{
struct V_9 * V_10 ;
struct V_19 * V_20 ;
if ( ! V_2 )
return;
V_10 = V_2 -> V_10 ;
V_20 = & V_10 -> V_13 ;
F_10 ( V_2 ) ;
F_6 ( L_3 , V_2 ) ;
if ( V_20 -> V_21 -> V_32 ) {
V_20 -> V_21 -> V_32 ( V_2 ) ;
} else {
F_1 ( V_2 ) ;
F_2 ( V_2 ) ;
}
}
struct V_33 *
F_12 ( struct V_1 * V_2 ,
struct V_27 * V_28 )
{
int V_34 , V_35 = F_13 ( V_28 ) ;
struct V_33 * V_36 ;
V_36 = F_14 ( V_2 , V_28 ) ;
if ( V_36 )
return V_36 ;
V_34 = F_15 ( & V_28 -> V_37 , V_2 -> V_38 ) ;
if ( V_34 )
return F_16 ( V_34 ) ;
V_36 = V_28 -> V_21 -> V_39 ( V_28 ) ;
if ( ! V_36 )
return F_16 ( - V_18 ) ;
V_2 -> V_6 [ V_35 ] = V_36 ;
V_2 -> V_5 [ V_35 ] = V_28 ;
V_36 -> V_2 = V_2 ;
F_6 ( L_4 ,
V_28 -> V_40 . V_41 , V_36 , V_2 ) ;
return V_36 ;
}
int F_17 ( struct V_33 * V_2 ,
struct V_42 * V_43 )
{
struct V_44 V_45 ;
if ( V_43 && memcmp ( & V_2 -> V_43 , V_43 , sizeof( * V_43 ) ) == 0 )
return 0 ;
if ( V_2 -> V_46 )
F_18 ( V_2 -> V_46 ) ;
V_2 -> V_46 = NULL ;
if ( V_43 ) {
F_19 ( & V_45 , V_43 ) ;
V_2 -> V_46 =
F_20 ( V_2 -> V_28 -> V_10 ,
sizeof( V_45 ) ,
& V_45 ) ;
if ( F_21 ( V_2 -> V_46 ) )
return F_22 ( V_2 -> V_46 ) ;
F_23 ( & V_2 -> V_43 , V_43 ) ;
V_2 -> V_47 = true ;
F_6 ( L_5 ,
V_43 -> V_48 , V_2 ) ;
} else {
memset ( & V_2 -> V_43 , 0 , sizeof( V_2 -> V_43 ) ) ;
V_2 -> V_47 = false ;
F_6 ( L_6 ,
V_2 ) ;
}
return 0 ;
}
int F_24 ( struct V_33 * V_2 ,
struct V_49 * V_50 )
{
if ( V_50 == V_2 -> V_46 )
return 0 ;
if ( V_2 -> V_46 )
F_18 ( V_2 -> V_46 ) ;
V_2 -> V_46 = NULL ;
if ( V_50 ) {
if ( V_50 -> V_51 != sizeof( struct V_44 ) ||
F_25 ( & V_2 -> V_43 ,
( const struct V_44 * )
V_50 -> V_52 ) )
return - V_53 ;
V_2 -> V_46 = F_26 ( V_50 ) ;
V_2 -> V_47 = true ;
F_6 ( L_5 ,
V_2 -> V_43 . V_48 , V_2 ) ;
} else {
memset ( & V_2 -> V_43 , 0 , sizeof( V_2 -> V_43 ) ) ;
V_2 -> V_47 = false ;
F_6 ( L_6 ,
V_2 ) ;
}
return 0 ;
}
int F_27 ( struct V_27 * V_28 ,
struct V_33 * V_2 , struct V_54 * V_55 ,
T_1 V_56 )
{
struct V_9 * V_10 = V_28 -> V_10 ;
struct V_19 * V_20 = & V_10 -> V_13 ;
int V_34 ;
if ( V_55 == V_20 -> V_57 )
V_2 -> V_58 = V_56 ;
else if ( V_55 == V_20 -> V_59 ) {
struct V_49 * V_43 =
F_28 ( V_10 , V_56 ) ;
V_34 = F_24 ( V_2 , V_43 ) ;
if ( V_43 )
F_18 ( V_43 ) ;
return V_34 ;
}
else if ( V_28 -> V_21 -> V_60 )
return V_28 -> V_21 -> V_60 ( V_28 , V_2 , V_55 , V_56 ) ;
else
return - V_53 ;
return 0 ;
}
int F_29 ( struct V_27 * V_28 ,
const struct V_33 * V_2 ,
struct V_54 * V_55 , T_1 * V_56 )
{
struct V_9 * V_10 = V_28 -> V_10 ;
struct V_19 * V_20 = & V_10 -> V_13 ;
if ( V_55 == V_20 -> V_57 )
* V_56 = V_2 -> V_58 ;
else if ( V_55 == V_20 -> V_59 )
* V_56 = ( V_2 -> V_46 ) ? V_2 -> V_46 -> V_40 . V_41 : 0 ;
else if ( V_28 -> V_21 -> V_61 )
return V_28 -> V_21 -> V_61 ( V_28 , V_2 , V_55 , V_56 ) ;
else
return - V_53 ;
return 0 ;
}
static int F_30 ( struct V_27 * V_28 ,
struct V_33 * V_2 )
{
if ( V_2 -> V_58 && ! V_2 -> V_47 ) {
F_6 ( L_7 ,
V_28 -> V_40 . V_41 ) ;
return - V_53 ;
}
if ( F_31 ( V_28 -> V_10 , V_62 ) &&
F_32 ( V_2 -> V_47 && ! V_2 -> V_46 ) ) {
F_6 ( L_8 ,
V_28 -> V_40 . V_41 ) ;
return - V_53 ;
}
if ( F_31 ( V_28 -> V_10 , V_62 ) &&
F_32 ( ! V_2 -> V_47 && V_2 -> V_46 ) ) {
F_6 ( L_9 ,
V_28 -> V_40 . V_41 ) ;
return - V_53 ;
}
return 0 ;
}
struct V_63 *
F_33 ( struct V_1 * V_2 ,
struct V_29 * V_30 )
{
int V_34 , V_35 = F_34 ( V_30 ) ;
struct V_63 * V_64 ;
V_64 = F_35 ( V_2 , V_30 ) ;
if ( V_64 )
return V_64 ;
V_34 = F_15 ( & V_30 -> V_37 , V_2 -> V_38 ) ;
if ( V_34 )
return F_16 ( V_34 ) ;
V_64 = V_30 -> V_21 -> V_39 ( V_30 ) ;
if ( ! V_64 )
return F_16 ( - V_18 ) ;
V_2 -> V_8 [ V_35 ] = V_64 ;
V_2 -> V_7 [ V_35 ] = V_30 ;
V_64 -> V_2 = V_2 ;
F_6 ( L_10 ,
V_30 -> V_40 . V_41 , V_64 , V_2 ) ;
if ( V_64 -> V_28 ) {
struct V_33 * V_36 ;
V_36 = F_12 ( V_2 ,
V_64 -> V_28 ) ;
if ( F_21 ( V_36 ) )
return F_36 ( V_36 ) ;
}
return V_64 ;
}
int F_37 ( struct V_29 * V_30 ,
struct V_63 * V_2 , struct V_54 * V_55 ,
T_1 V_56 )
{
struct V_9 * V_10 = V_30 -> V_10 ;
struct V_19 * V_20 = & V_10 -> V_13 ;
if ( V_55 == V_20 -> V_65 ) {
struct V_66 * V_67 = F_38 ( V_10 , V_56 ) ;
F_39 ( V_2 , V_67 ) ;
if ( V_67 )
F_40 ( V_67 ) ;
} else if ( V_55 == V_20 -> V_68 ) {
struct V_27 * V_28 = F_41 ( V_10 , V_56 ) ;
return F_42 ( V_2 , V_28 ) ;
} else if ( V_55 == V_20 -> V_69 ) {
V_2 -> V_70 = F_43 ( V_56 ) ;
} else if ( V_55 == V_20 -> V_71 ) {
V_2 -> V_72 = F_43 ( V_56 ) ;
} else if ( V_55 == V_20 -> V_73 ) {
V_2 -> V_74 = V_56 ;
} else if ( V_55 == V_20 -> V_75 ) {
V_2 -> V_76 = V_56 ;
} else if ( V_55 == V_20 -> V_77 ) {
V_2 -> V_78 = V_56 ;
} else if ( V_55 == V_20 -> V_79 ) {
V_2 -> V_80 = V_56 ;
} else if ( V_55 == V_20 -> V_81 ) {
V_2 -> V_82 = V_56 ;
} else if ( V_55 == V_20 -> V_83 ) {
V_2 -> V_84 = V_56 ;
} else if ( V_55 == V_20 -> V_85 ) {
V_2 -> V_86 = V_56 ;
} else if ( V_30 -> V_21 -> V_60 ) {
return V_30 -> V_21 -> V_60 ( V_30 , V_2 ,
V_55 , V_56 ) ;
} else {
return - V_53 ;
}
return 0 ;
}
static int
F_44 ( struct V_29 * V_30 ,
const struct V_63 * V_2 ,
struct V_54 * V_55 , T_1 * V_56 )
{
struct V_9 * V_10 = V_30 -> V_10 ;
struct V_19 * V_20 = & V_10 -> V_13 ;
if ( V_55 == V_20 -> V_65 ) {
* V_56 = ( V_2 -> V_67 ) ? V_2 -> V_67 -> V_40 . V_41 : 0 ;
} else if ( V_55 == V_20 -> V_68 ) {
* V_56 = ( V_2 -> V_28 ) ? V_2 -> V_28 -> V_40 . V_41 : 0 ;
} else if ( V_55 == V_20 -> V_69 ) {
* V_56 = F_45 ( V_2 -> V_70 ) ;
} else if ( V_55 == V_20 -> V_71 ) {
* V_56 = F_45 ( V_2 -> V_72 ) ;
} else if ( V_55 == V_20 -> V_73 ) {
* V_56 = V_2 -> V_74 ;
} else if ( V_55 == V_20 -> V_75 ) {
* V_56 = V_2 -> V_76 ;
} else if ( V_55 == V_20 -> V_77 ) {
* V_56 = V_2 -> V_78 ;
} else if ( V_55 == V_20 -> V_79 ) {
* V_56 = V_2 -> V_80 ;
} else if ( V_55 == V_20 -> V_81 ) {
* V_56 = V_2 -> V_82 ;
} else if ( V_55 == V_20 -> V_83 ) {
* V_56 = V_2 -> V_84 ;
} else if ( V_55 == V_20 -> V_85 ) {
* V_56 = V_2 -> V_86 ;
} else if ( V_30 -> V_21 -> V_61 ) {
return V_30 -> V_21 -> V_61 ( V_30 , V_2 , V_55 , V_56 ) ;
} else {
return - V_53 ;
}
return 0 ;
}
static int F_46 ( struct V_29 * V_30 ,
struct V_63 * V_2 )
{
unsigned int V_87 , V_88 ;
int V_34 ;
if ( F_32 ( V_2 -> V_28 && ! V_2 -> V_67 ) ) {
F_6 ( L_11 ) ;
return - V_53 ;
} else if ( F_32 ( V_2 -> V_67 && ! V_2 -> V_28 ) ) {
F_6 ( L_12 ) ;
return - V_53 ;
}
if ( ! V_2 -> V_28 )
return 0 ;
if ( ! ( V_30 -> V_89 & F_47 ( V_2 -> V_28 ) ) ) {
F_6 ( L_13 ) ;
return - V_53 ;
}
V_34 = F_48 ( V_30 , V_2 -> V_67 -> V_90 ) ;
if ( V_34 ) {
F_6 ( L_14 ,
F_49 ( V_2 -> V_67 -> V_90 ) ) ;
return V_34 ;
}
if ( V_2 -> V_74 > V_91 ||
V_2 -> V_70 > V_91 - ( V_92 ) V_2 -> V_74 ||
V_2 -> V_76 > V_91 ||
V_2 -> V_72 > V_91 - ( V_92 ) V_2 -> V_76 ) {
F_6 ( L_15 ,
V_2 -> V_74 , V_2 -> V_76 ,
V_2 -> V_70 , V_2 -> V_72 ) ;
return - V_93 ;
}
V_87 = V_2 -> V_67 -> V_94 << 16 ;
V_88 = V_2 -> V_67 -> V_95 << 16 ;
if ( V_2 -> V_82 > V_87 ||
V_2 -> V_78 > V_87 - V_2 -> V_82 ||
V_2 -> V_84 > V_88 ||
V_2 -> V_80 > V_88 - V_2 -> V_84 ) {
F_6 ( L_16
L_17 ,
V_2 -> V_82 >> 16 , ( ( V_2 -> V_82 & 0xffff ) * 15625 ) >> 10 ,
V_2 -> V_84 >> 16 , ( ( V_2 -> V_84 & 0xffff ) * 15625 ) >> 10 ,
V_2 -> V_78 >> 16 , ( ( V_2 -> V_78 & 0xffff ) * 15625 ) >> 10 ,
V_2 -> V_80 >> 16 , ( ( V_2 -> V_80 & 0xffff ) * 15625 ) >> 10 ) ;
return - V_96 ;
}
return 0 ;
}
struct V_97 *
F_50 ( struct V_1 * V_2 ,
struct V_24 * V_25 )
{
int V_34 , V_35 ;
struct V_19 * V_20 = & V_25 -> V_10 -> V_13 ;
struct V_97 * V_98 ;
V_34 = F_15 ( & V_20 -> V_99 , V_2 -> V_38 ) ;
if ( V_34 )
return F_16 ( V_34 ) ;
V_35 = F_51 ( V_25 ) ;
if ( V_35 >= V_2 -> V_12 ) {
F_6 ( L_18 ) ;
return F_16 ( - V_100 ) ;
}
if ( V_2 -> V_4 [ V_35 ] )
return V_2 -> V_4 [ V_35 ] ;
V_98 = V_25 -> V_21 -> V_39 ( V_25 ) ;
if ( ! V_98 )
return F_16 ( - V_18 ) ;
V_2 -> V_4 [ V_35 ] = V_98 ;
V_2 -> V_3 [ V_35 ] = V_25 ;
V_98 -> V_2 = V_2 ;
F_6 ( L_19 ,
V_25 -> V_40 . V_41 , V_98 , V_2 ) ;
if ( V_98 -> V_28 ) {
struct V_33 * V_36 ;
V_36 = F_12 ( V_2 ,
V_98 -> V_28 ) ;
if ( F_21 ( V_36 ) )
return F_36 ( V_36 ) ;
}
return V_98 ;
}
int F_52 ( struct V_24 * V_25 ,
struct V_97 * V_2 , struct V_54 * V_55 ,
T_1 V_56 )
{
struct V_9 * V_10 = V_25 -> V_10 ;
struct V_19 * V_20 = & V_10 -> V_13 ;
if ( V_55 == V_20 -> V_68 ) {
struct V_27 * V_28 = F_41 ( V_10 , V_56 ) ;
return F_53 ( V_2 , V_28 ) ;
} else if ( V_55 == V_20 -> V_101 ) {
return - V_53 ;
} else if ( V_25 -> V_21 -> V_60 ) {
return V_25 -> V_21 -> V_60 ( V_25 ,
V_2 , V_55 , V_56 ) ;
} else {
return - V_53 ;
}
}
static int
F_54 ( struct V_24 * V_25 ,
const struct V_97 * V_2 ,
struct V_54 * V_55 , T_1 * V_56 )
{
struct V_9 * V_10 = V_25 -> V_10 ;
struct V_19 * V_20 = & V_10 -> V_13 ;
if ( V_55 == V_20 -> V_68 ) {
* V_56 = ( V_2 -> V_28 ) ? V_2 -> V_28 -> V_40 . V_41 : 0 ;
} else if ( V_55 == V_20 -> V_101 ) {
* V_56 = V_25 -> V_102 ;
} else if ( V_25 -> V_21 -> V_61 ) {
return V_25 -> V_21 -> V_61 ( V_25 ,
V_2 , V_55 , V_56 ) ;
} else {
return - V_53 ;
}
return 0 ;
}
int F_55 ( struct V_103 * V_104 ,
struct V_54 * V_55 , T_1 * V_56 )
{
struct V_9 * V_10 = V_55 -> V_10 ;
int V_34 ;
switch ( V_104 -> type ) {
case V_105 : {
struct V_24 * V_25 = F_56 ( V_104 ) ;
F_32 ( ! F_57 ( & V_10 -> V_13 . V_99 ) ) ;
V_34 = F_54 ( V_25 ,
V_25 -> V_2 , V_55 , V_56 ) ;
break;
}
case V_106 : {
struct V_27 * V_28 = F_58 ( V_104 ) ;
F_32 ( ! F_57 ( & V_28 -> V_37 ) ) ;
V_34 = F_29 ( V_28 ,
V_28 -> V_2 , V_55 , V_56 ) ;
break;
}
case V_107 : {
struct V_29 * V_30 = F_59 ( V_104 ) ;
F_32 ( ! F_57 ( & V_30 -> V_37 ) ) ;
V_34 = F_44 ( V_30 ,
V_30 -> V_2 , V_55 , V_56 ) ;
break;
}
default:
V_34 = - V_53 ;
break;
}
return V_34 ;
}
int
F_42 ( struct V_63 * V_64 ,
struct V_27 * V_28 )
{
struct V_29 * V_30 = V_64 -> V_30 ;
struct V_33 * V_36 ;
if ( V_64 -> V_28 ) {
V_36 = F_12 ( V_64 -> V_2 ,
V_64 -> V_28 ) ;
if ( F_32 ( F_21 ( V_36 ) ) )
return F_22 ( V_36 ) ;
V_36 -> V_108 &= ~ ( 1 << F_34 ( V_30 ) ) ;
}
V_64 -> V_28 = V_28 ;
if ( V_28 ) {
V_36 = F_12 ( V_64 -> V_2 ,
V_28 ) ;
if ( F_21 ( V_36 ) )
return F_22 ( V_36 ) ;
V_36 -> V_108 |= ( 1 << F_34 ( V_30 ) ) ;
}
if ( V_28 )
F_6 ( L_20 ,
V_64 , V_28 -> V_40 . V_41 ) ;
else
F_6 ( L_21 ,
V_64 ) ;
return 0 ;
}
void
F_39 ( struct V_63 * V_64 ,
struct V_66 * V_67 )
{
if ( V_64 -> V_67 )
F_40 ( V_64 -> V_67 ) ;
if ( V_67 )
F_60 ( V_67 ) ;
V_64 -> V_67 = V_67 ;
if ( V_67 )
F_6 ( L_22 ,
V_67 -> V_40 . V_41 , V_64 ) ;
else
F_6 ( L_23 ,
V_64 ) ;
}
int
F_53 ( struct V_97 * V_109 ,
struct V_27 * V_28 )
{
struct V_33 * V_36 ;
if ( V_28 ) {
V_36 = F_12 ( V_109 -> V_2 , V_28 ) ;
if ( F_21 ( V_36 ) )
return F_22 ( V_36 ) ;
}
V_109 -> V_28 = V_28 ;
if ( V_28 )
F_6 ( L_24 ,
V_109 , V_28 -> V_40 . V_41 ) ;
else
F_6 ( L_25 ,
V_109 ) ;
return 0 ;
}
int
F_61 ( struct V_1 * V_2 ,
struct V_27 * V_28 )
{
struct V_19 * V_20 = & V_2 -> V_10 -> V_13 ;
struct V_24 * V_25 ;
struct V_97 * V_109 ;
int V_34 ;
V_34 = F_15 ( & V_20 -> V_99 , V_2 -> V_38 ) ;
if ( V_34 )
return V_34 ;
F_6 ( L_26 ,
V_28 -> V_40 . V_41 , V_2 ) ;
F_62 (connector, state->dev) {
if ( V_25 -> V_2 -> V_28 != V_28 )
continue;
V_109 = F_50 ( V_2 , V_25 ) ;
if ( F_21 ( V_109 ) )
return F_22 ( V_109 ) ;
}
return 0 ;
}
int
F_63 ( struct V_1 * V_2 ,
struct V_27 * V_28 )
{
struct V_29 * V_30 ;
F_32 ( ! F_14 ( V_2 , V_28 ) ) ;
F_64 (plane, state->dev, crtc->state->plane_mask) {
struct V_63 * V_64 =
F_33 ( V_2 , V_30 ) ;
if ( F_21 ( V_64 ) )
return F_22 ( V_64 ) ;
}
return 0 ;
}
int
F_65 ( struct V_1 * V_2 ,
struct V_27 * V_28 )
{
struct V_24 * V_25 ;
struct V_97 * V_109 ;
int V_23 , V_110 = 0 ;
F_66 (state, connector, conn_state, i) {
if ( V_109 -> V_28 == V_28 )
V_110 ++ ;
}
F_6 ( L_27 ,
V_2 , V_110 , V_28 -> V_40 . V_41 ) ;
return V_110 ;
}
void F_67 ( struct V_1 * V_2 )
{
int V_34 ;
V_111:
F_68 ( V_2 -> V_38 ) ;
V_34 = F_15 ( & V_2 -> V_10 -> V_13 . V_99 ,
V_2 -> V_38 ) ;
if ( V_34 )
goto V_111;
V_34 = F_69 ( V_2 -> V_10 ,
V_2 -> V_38 ) ;
if ( V_34 )
goto V_111;
}
int F_70 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = V_2 -> V_10 ;
struct V_19 * V_20 = & V_10 -> V_13 ;
struct V_29 * V_30 ;
struct V_63 * V_64 ;
struct V_27 * V_28 ;
struct V_33 * V_36 ;
int V_23 , V_34 = 0 ;
F_6 ( L_28 , V_2 ) ;
F_71 (state, plane, plane_state, i) {
V_34 = F_46 ( V_30 , V_64 ) ;
if ( V_34 ) {
F_6 ( L_29 ,
V_30 -> V_40 . V_41 ) ;
return V_34 ;
}
}
F_72 (state, crtc, crtc_state, i) {
V_34 = F_30 ( V_28 , V_36 ) ;
if ( V_34 ) {
F_6 ( L_30 ,
V_28 -> V_40 . V_41 ) ;
return V_34 ;
}
}
if ( V_20 -> V_21 -> V_112 )
V_34 = V_20 -> V_21 -> V_112 ( V_2 -> V_10 , V_2 ) ;
if ( ! V_2 -> V_11 ) {
F_72 (state, crtc, crtc_state, i) {
if ( F_73 ( V_36 ) ) {
F_6 ( L_31 ,
V_28 -> V_40 . V_41 ) ;
return - V_53 ;
}
}
}
return V_34 ;
}
int F_74 ( struct V_1 * V_2 )
{
struct V_19 * V_20 = & V_2 -> V_10 -> V_13 ;
int V_34 ;
V_34 = F_70 ( V_2 ) ;
if ( V_34 )
return V_34 ;
F_6 ( L_32 , V_2 ) ;
return V_20 -> V_21 -> V_113 ( V_2 -> V_10 , V_2 , false ) ;
}
int F_75 ( struct V_1 * V_2 )
{
struct V_19 * V_20 = & V_2 -> V_10 -> V_13 ;
int V_34 ;
V_34 = F_70 ( V_2 ) ;
if ( V_34 )
return V_34 ;
F_6 ( L_33 , V_2 ) ;
return V_20 -> V_21 -> V_113 ( V_2 -> V_10 , V_2 , true ) ;
}
static struct V_114 * F_76 (
struct V_9 * V_10 , struct V_115 * V_116 , T_1 V_117 )
{
struct V_114 * V_118 = NULL ;
unsigned long V_119 ;
F_77 ( & V_10 -> V_120 , V_119 ) ;
if ( V_116 -> V_121 < sizeof V_118 -> V_122 ) {
F_78 ( & V_10 -> V_120 , V_119 ) ;
goto V_123;
}
V_116 -> V_121 -= sizeof V_118 -> V_122 ;
F_78 ( & V_10 -> V_120 , V_119 ) ;
V_118 = F_8 ( sizeof *V_118 , V_15 ) ;
if ( V_118 == NULL ) {
F_77 ( & V_10 -> V_120 , V_119 ) ;
V_116 -> V_121 += sizeof V_118 -> V_122 ;
F_78 ( & V_10 -> V_120 , V_119 ) ;
goto V_123;
}
V_118 -> V_122 . V_40 . type = V_124 ;
V_118 -> V_122 . V_40 . V_51 = sizeof V_118 -> V_122 ;
V_118 -> V_122 . V_117 = V_117 ;
V_118 -> V_40 . V_122 = & V_118 -> V_122 . V_40 ;
V_118 -> V_40 . V_116 = V_116 ;
V_118 -> V_40 . V_125 = ( void ( * ) ( struct V_126 * ) ) F_2 ;
V_123:
return V_118 ;
}
static void F_79 ( struct V_9 * V_10 ,
struct V_115 * V_116 , struct V_114 * V_118 )
{
unsigned long V_119 ;
F_77 ( & V_10 -> V_120 , V_119 ) ;
V_116 -> V_121 += sizeof V_118 -> V_122 ;
F_78 ( & V_10 -> V_120 , V_119 ) ;
F_2 ( V_118 ) ;
}
static int F_80 ( struct V_1 * V_2 ,
struct V_103 * V_104 , struct V_54 * V_127 ,
T_1 V_128 )
{
struct V_103 * V_129 ;
int V_34 ;
if ( ! F_81 ( V_127 , V_128 , & V_129 ) )
return - V_53 ;
switch ( V_104 -> type ) {
case V_105 : {
struct V_24 * V_25 = F_56 ( V_104 ) ;
struct V_97 * V_98 ;
V_98 = F_50 ( V_2 , V_25 ) ;
if ( F_21 ( V_98 ) ) {
V_34 = F_22 ( V_98 ) ;
break;
}
V_34 = F_52 ( V_25 ,
V_98 , V_127 , V_128 ) ;
break;
}
case V_106 : {
struct V_27 * V_28 = F_58 ( V_104 ) ;
struct V_33 * V_36 ;
V_36 = F_12 ( V_2 , V_28 ) ;
if ( F_21 ( V_36 ) ) {
V_34 = F_22 ( V_36 ) ;
break;
}
V_34 = F_27 ( V_28 ,
V_36 , V_127 , V_128 ) ;
break;
}
case V_107 : {
struct V_29 * V_30 = F_59 ( V_104 ) ;
struct V_63 * V_64 ;
V_64 = F_33 ( V_2 , V_30 ) ;
if ( F_21 ( V_64 ) ) {
V_34 = F_22 ( V_64 ) ;
break;
}
V_34 = F_37 ( V_30 ,
V_64 , V_127 , V_128 ) ;
break;
}
default:
V_34 = - V_53 ;
break;
}
F_82 ( V_127 , V_129 ) ;
return V_34 ;
}
int F_83 ( struct V_9 * V_10 ,
void * V_52 , struct V_115 * V_116 )
{
struct V_130 * V_131 = V_52 ;
T_2 T_3 * V_132 = ( T_2 T_3 * ) ( unsigned long ) ( V_131 -> V_132 ) ;
T_2 T_3 * V_133 = ( T_2 T_3 * ) ( unsigned long ) ( V_131 -> V_133 ) ;
T_2 T_3 * V_134 = ( T_2 T_3 * ) ( unsigned long ) ( V_131 -> V_134 ) ;
T_1 T_3 * V_135 = ( T_1 T_3 * ) ( unsigned long ) ( V_131 -> V_135 ) ;
unsigned int V_136 , V_137 ;
struct V_1 * V_2 ;
struct V_138 V_139 ;
struct V_29 * V_30 ;
struct V_27 * V_28 ;
struct V_33 * V_36 ;
unsigned V_108 = 0 ;
int V_34 = 0 ;
unsigned int V_23 , V_140 ;
if ( ! F_31 ( V_10 , V_62 ) )
return - V_53 ;
if ( ! V_116 -> V_141 )
return - V_53 ;
if ( V_131 -> V_119 & ~ V_142 )
return - V_53 ;
if ( V_131 -> V_143 )
return - V_53 ;
if ( ( V_131 -> V_119 & V_144 ) &&
! V_10 -> V_13 . V_145 )
return - V_53 ;
if ( ( V_131 -> V_119 & V_146 ) &&
( V_131 -> V_119 & V_147 ) )
return - V_53 ;
F_84 ( & V_139 , 0 ) ;
V_2 = F_7 ( V_10 ) ;
if ( ! V_2 )
return - V_18 ;
V_2 -> V_38 = & V_139 ;
V_2 -> V_11 = ! ! ( V_131 -> V_119 & V_148 ) ;
V_111:
V_136 = 0 ;
V_137 = 0 ;
for ( V_23 = 0 ; V_23 < V_131 -> V_149 ; V_23 ++ ) {
T_2 V_150 , V_151 ;
struct V_103 * V_104 ;
if ( F_85 ( V_150 , V_132 + V_136 ) ) {
V_34 = - V_152 ;
goto V_123;
}
V_104 = F_86 ( V_10 , V_150 , V_153 ) ;
if ( ! V_104 || ! V_104 -> V_154 ) {
V_34 = - V_155 ;
goto V_123;
}
if ( F_85 ( V_151 , V_133 + V_136 ) ) {
V_34 = - V_152 ;
goto V_123;
}
V_136 ++ ;
for ( V_140 = 0 ; V_140 < V_151 ; V_140 ++ ) {
T_2 V_156 ;
T_1 V_128 ;
struct V_54 * V_127 ;
if ( F_85 ( V_156 , V_134 + V_137 ) ) {
V_34 = - V_152 ;
goto V_123;
}
V_127 = F_87 ( V_10 , V_156 ) ;
if ( ! V_127 ) {
V_34 = - V_155 ;
goto V_123;
}
if ( F_88 ( & V_128 ,
V_135 + V_137 ,
sizeof( V_128 ) ) ) {
V_34 = - V_152 ;
goto V_123;
}
V_34 = F_80 ( V_2 , V_104 , V_127 , V_128 ) ;
if ( V_34 )
goto V_123;
V_137 ++ ;
}
if ( V_104 -> type == V_107 && V_151 &&
! ( V_131 -> V_119 & V_146 ) ) {
V_30 = F_59 ( V_104 ) ;
V_108 |= ( 1 << F_34 ( V_30 ) ) ;
V_30 -> V_157 = V_30 -> V_67 ;
}
}
if ( V_131 -> V_119 & V_147 ) {
F_72 (state, crtc, crtc_state, i) {
struct V_114 * V_118 ;
V_118 = F_76 ( V_10 , V_116 , V_131 -> V_117 ) ;
if ( ! V_118 ) {
V_34 = - V_18 ;
goto V_123;
}
V_36 -> V_122 = V_118 ;
}
}
if ( V_131 -> V_119 & V_146 ) {
V_34 = F_70 ( V_2 ) ;
} else if ( V_131 -> V_119 & V_158 ) {
V_34 = F_75 ( V_2 ) ;
} else {
V_34 = F_74 ( V_2 ) ;
}
V_123:
F_64 (plane, dev, plane_mask) {
if ( V_34 == 0 ) {
struct V_66 * V_159 = V_30 -> V_2 -> V_67 ;
if ( V_159 )
F_60 ( V_159 ) ;
V_30 -> V_67 = V_159 ;
V_30 -> V_28 = V_30 -> V_2 -> V_28 ;
if ( V_30 -> V_157 )
F_40 ( V_30 -> V_157 ) ;
}
V_30 -> V_157 = NULL ;
}
if ( V_34 && V_131 -> V_119 & V_147 ) {
F_72 (state, crtc, crtc_state, i) {
if ( ! V_36 -> V_122 )
continue;
F_79 ( V_10 , V_116 ,
V_36 -> V_122 ) ;
}
}
if ( V_34 == - V_160 ) {
F_10 ( V_2 ) ;
F_68 ( & V_139 ) ;
goto V_111;
}
if ( V_34 || V_131 -> V_119 & V_146 )
F_11 ( V_2 ) ;
F_89 ( & V_139 ) ;
F_90 ( & V_139 ) ;
return V_34 ;
}
