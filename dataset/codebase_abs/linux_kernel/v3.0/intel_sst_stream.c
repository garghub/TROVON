int F_1 ( T_1 V_1 , T_1 V_2 , T_1 * V_3 )
{
if ( V_1 >= V_4 ) {
F_2 ( L_1 , V_1 ) ;
return - V_5 ;
}
if ( V_6 -> V_7 [ V_1 ] . V_8 == V_9 ) {
if ( V_1 == V_10 && V_2 == 1 )
* V_3 = 0x10 ;
else if ( V_1 == V_11 && V_2 == 1 )
* V_3 = 0x20 ;
else if ( V_1 == V_12 && V_2 == 1 )
* V_3 = 0x04 ;
else if ( V_1 == V_12 && V_2 == 2 )
* V_3 = 0x0C ;
else if ( V_1 == V_13 && V_2 == 1 )
* V_3 = 0x01 ;
else if ( V_1 == V_13 && V_2 == 2 )
* V_3 = 0x03 ;
else if ( V_1 == V_14 && V_2 == 1 )
* V_3 = 0x01 ;
else if ( V_1 == V_14 && V_2 == 2 )
* V_3 = 0x03 ;
else if ( V_1 == V_14 && V_2 == 3 )
* V_3 = 0x07 ;
else if ( V_1 == V_14 && V_2 == 4 )
* V_3 = 0x0F ;
else if ( V_1 == V_14 && V_2 > 4 )
* V_3 = 0x1F ;
else {
F_2 ( L_2 ) ;
return - V_5 ;
}
} else {
F_2 ( L_3 ,
V_6 -> V_7 [ V_1 ] . V_8 ) ;
return - V_15 ;
}
F_2 ( L_4 , * V_3 ) ;
return 0 ;
}
static unsigned int F_3 ( void )
{
int V_16 ;
for ( V_16 = 1 ; V_16 <= V_17 ; V_16 ++ ) {
if ( V_6 -> V_7 [ V_16 ] . V_8 == V_9 )
return V_16 ;
}
F_2 ( L_5 ) ;
return - V_18 ;
}
int F_4 ( char * V_19 , unsigned int V_20 ,
T_2 V_21 , unsigned int V_1 )
{
struct V_22 * V_23 = NULL ;
struct V_24 V_25 ;
unsigned int V_3 = 0 , V_26 ;
int V_27 ;
struct V_28 * V_29 ;
struct V_30 * V_31 ;
F_2 ( L_6 ) ;
F_2 ( L_7 , V_20 , V_21 , V_1 ) ;
F_5 ( ! V_19 ) ;
V_29 = (struct V_28 * ) V_19 ;
V_26 = V_29 -> V_32 . V_33 . V_2 ;
if ( V_6 -> V_34 == V_35 ) {
if ( F_1 ( V_1 , V_26 , & V_3 ) )
return - V_5 ;
F_6 ( & V_6 -> V_36 ) ;
V_27 = V_1 ;
F_7 ( & V_6 -> V_36 ) ;
F_2 ( L_8 , V_3 ) ;
} else {
F_6 ( & V_6 -> V_36 ) ;
V_27 = F_3 () ;
F_7 ( & V_6 -> V_36 ) ;
if ( V_27 <= 0 )
return - V_18 ;
}
F_8 ( & V_6 -> V_7 [ V_27 ] , V_21 ,
V_27 , V_20 , V_3 , V_1 ) ;
if ( F_9 ( & V_23 ) )
return - V_37 ;
F_10 ( & V_23 -> V_38 , V_39 , 1 , V_27 ) ;
V_23 -> V_38 . V_40 . V_41 = sizeof( V_25 ) + sizeof( T_1 ) ;
V_25 . V_42 . V_43 = V_21 ;
V_25 . V_42 . V_42 = V_44 ;
V_25 . V_42 . V_45 = V_20 ;
V_25 . V_42 . V_46 = 0 ;
V_25 . V_42 . V_47 = V_3 ;
V_25 . V_42 . V_48 = V_25 . V_42 . V_49 = 0 ;
memcpy ( & V_25 . V_50 , V_19 ,
sizeof( struct V_28 ) ) ;
memcpy ( V_23 -> V_51 , & V_23 -> V_38 , sizeof( T_1 ) ) ;
memcpy ( V_23 -> V_51 + sizeof( T_1 ) , & V_25 ,
sizeof( V_25 ) ) ;
V_31 = & V_6 -> V_7 [ V_27 ] ;
V_31 -> V_52 . V_53 = false ;
V_31 -> V_52 . V_54 = 0 ;
V_31 -> V_52 . V_55 = true ;
F_11 ( & V_6 -> V_56 ) ;
F_12 ( & V_23 -> V_57 , & V_6 -> V_58 ) ;
F_13 ( & V_6 -> V_56 ) ;
F_14 ( & V_6 -> V_59 ) ;
F_2 ( L_9 ) ;
return V_27 ;
}
int F_15 ( unsigned int V_27 ,
struct V_60 * V_61 )
{
int V_62 = 0 ;
struct V_30 * V_31 ;
struct V_63 * V_64 ;
F_2 ( L_10 , V_27 ) ;
V_31 = & V_6 -> V_7 [ V_27 ] ;
if ( V_61 -> V_42 . V_48 == V_65 ) {
V_64 = F_16 ( sizeof( * V_64 ) , V_66 ) ;
memcpy ( V_64 , & V_61 -> V_64 , sizeof( * V_64 ) ) ;
} else
V_64 = NULL ;
if ( V_31 -> V_52 . V_55 == true ) {
V_31 -> V_52 . V_55 = false ;
V_31 -> V_52 . V_41 = V_64 ;
V_31 -> V_52 . V_53 = true ;
V_31 -> V_52 . V_54 = V_61 -> V_42 . V_48 ;
F_2 ( L_11 ) ;
F_17 ( & V_6 -> V_67 ) ;
}
return V_62 ;
}
int F_18 ( struct V_68 * V_69 )
{
int V_62 = 0 ;
struct V_22 * V_23 = NULL ;
F_2 ( L_12 ) ;
if ( F_19 ( & V_23 ) ) {
F_20 ( L_13 ) ;
return - V_37 ;
}
F_10 ( & V_23 -> V_38 , V_70 , 0 , 0 ) ;
V_6 -> V_71 . V_53 = false ;
V_6 -> V_71 . V_54 = 0 ;
V_6 -> V_71 . V_55 = true ;
V_6 -> V_71 . V_41 = V_69 ;
F_11 ( & V_6 -> V_56 ) ;
F_12 ( & V_23 -> V_57 , & V_6 -> V_58 ) ;
F_13 ( & V_6 -> V_56 ) ;
F_14 ( & V_6 -> V_59 ) ;
V_62 = F_21 ( V_6 ,
& V_6 -> V_71 , V_72 ) ;
if ( V_62 ) {
F_20 ( L_14 , V_62 ) ;
V_62 = - V_73 ;
}
return V_62 ;
}
int F_22 ( int V_27 )
{
int V_62 = 0 ;
struct V_22 * V_23 = NULL ;
struct V_30 * V_31 ;
F_2 ( L_15 , V_27 ) ;
V_62 = F_23 ( V_27 ) ;
if ( V_62 )
return V_62 ;
V_31 = & V_6 -> V_7 [ V_27 ] ;
if ( V_31 -> V_8 != V_74 )
return - V_15 ;
if ( F_19 ( & V_23 ) )
return - V_37 ;
F_10 ( & V_23 -> V_38 , V_75 , 0 , V_27 ) ;
F_11 ( & V_6 -> V_56 ) ;
F_12 ( & V_23 -> V_57 , & V_6 -> V_58 ) ;
F_13 ( & V_6 -> V_56 ) ;
F_14 ( & V_6 -> V_59 ) ;
return V_62 ;
}
int F_24 ( int V_27 )
{
int V_62 = 0 ;
struct V_22 * V_23 = NULL ;
struct V_30 * V_31 ;
F_2 ( L_16 , V_27 ) ;
V_62 = F_23 ( V_27 ) ;
if ( V_62 )
return V_62 ;
V_31 = & V_6 -> V_7 [ V_27 ] ;
if ( V_31 -> V_8 == V_76 )
return 0 ;
if ( V_31 -> V_8 == V_77 ||
V_31 -> V_8 == V_74 ) {
if ( V_31 -> V_78 == V_9 )
return - V_15 ;
if ( V_31 -> V_52 . V_55 == true ) {
F_20 ( L_17 ) ;
return - V_5 ;
}
if ( F_19 ( & V_23 ) )
return - V_37 ;
F_10 ( & V_23 -> V_38 , V_79 , 0 , V_27 ) ;
V_31 -> V_52 . V_53 = false ;
V_31 -> V_52 . V_54 = 0 ;
V_31 -> V_52 . V_55 = true ;
F_11 ( & V_6 -> V_56 ) ;
F_12 ( & V_23 -> V_57 ,
& V_6 -> V_58 ) ;
F_13 ( & V_6 -> V_56 ) ;
F_14 ( & V_6 -> V_59 ) ;
V_62 = F_21 ( V_6 ,
& V_31 -> V_52 , V_72 ) ;
if ( V_62 == 0 ) {
V_31 -> V_78 = V_31 -> V_8 ;
V_31 -> V_8 = V_76 ;
} else if ( V_62 == V_80 ) {
V_62 = - V_5 ;
F_6 ( & V_6 -> V_36 ) ;
F_25 ( V_31 ) ;
F_7 ( & V_6 -> V_36 ) ;
}
} else {
V_62 = - V_15 ;
F_20 ( L_18 ) ;
}
return V_62 ;
}
int F_26 ( int V_27 )
{
int V_62 = 0 ;
struct V_22 * V_23 = NULL ;
struct V_30 * V_31 ;
F_2 ( L_19 , V_27 ) ;
V_62 = F_23 ( V_27 ) ;
if ( V_62 )
return V_62 ;
V_31 = & V_6 -> V_7 [ V_27 ] ;
if ( V_31 -> V_8 == V_77 )
return 0 ;
if ( V_31 -> V_8 == V_76 ) {
if ( V_31 -> V_52 . V_55 == true ) {
F_20 ( L_20 ) ;
return - V_5 ;
}
if ( F_19 ( & V_23 ) ) {
F_20 ( L_21 ) ;
return - V_37 ;
}
F_10 ( & V_23 -> V_38 , V_81 , 0 , V_27 ) ;
V_31 -> V_52 . V_53 = false ;
V_31 -> V_52 . V_54 = 0 ;
V_31 -> V_52 . V_55 = true ;
F_11 ( & V_6 -> V_56 ) ;
F_12 ( & V_23 -> V_57 ,
& V_6 -> V_58 ) ;
F_13 ( & V_6 -> V_56 ) ;
F_14 ( & V_6 -> V_59 ) ;
V_62 = F_21 ( V_6 ,
& V_31 -> V_52 , V_72 ) ;
if ( ! V_62 ) {
if ( V_31 -> V_78 == V_77 )
V_31 -> V_8 = V_77 ;
else
V_31 -> V_8 = V_74 ;
V_31 -> V_78 = V_76 ;
} else if ( V_62 == - V_80 ) {
V_62 = - V_5 ;
F_6 ( & V_6 -> V_36 ) ;
F_25 ( V_31 ) ;
F_7 ( & V_6 -> V_36 ) ;
}
} else {
V_62 = - V_15 ;
F_20 ( L_18 ) ;
}
return V_62 ;
}
int F_27 ( int V_27 )
{
int V_62 = 0 ;
struct V_22 * V_23 = NULL ;
struct V_82 * V_83 = NULL , * V_84 ;
struct V_30 * V_31 ;
F_2 ( L_22 , V_27 ) ;
V_62 = F_23 ( V_27 ) ;
if ( V_62 )
return V_62 ;
V_31 = & V_6 -> V_7 [ V_27 ] ;
if ( V_31 -> V_8 != V_9 &&
V_31 -> V_8 != V_85 ) {
if ( V_31 -> V_52 . V_55 == true ) {
F_20 ( L_20 ) ;
return - V_5 ;
}
if ( F_19 ( & V_23 ) ) {
F_20 ( L_21 ) ;
return - V_37 ;
}
F_10 ( & V_23 -> V_38 , V_86 , 0 , V_27 ) ;
V_31 -> V_52 . V_53 = false ;
V_31 -> V_52 . V_54 = 0 ;
V_31 -> V_52 . V_55 = true ;
F_11 ( & V_6 -> V_56 ) ;
F_12 ( & V_23 -> V_57 ,
& V_6 -> V_58 ) ;
F_13 ( & V_6 -> V_56 ) ;
F_14 ( & V_6 -> V_59 ) ;
V_62 = F_21 ( V_6 ,
& V_31 -> V_52 , V_72 ) ;
if ( ! V_62 ) {
F_2 ( L_23 ) ;
V_31 -> V_78 = V_9 ;
V_31 -> V_8 = V_74 ;
if ( V_31 -> V_87 != V_88 ) {
F_6 ( & V_31 -> V_89 ) ;
F_28 (bufs, _bufs,
&str_info->bufs, node) {
F_29 ( & V_83 -> V_57 ) ;
F_30 ( V_83 ) ;
}
F_7 ( & V_31 -> V_89 ) ;
}
V_31 -> V_90 += V_31 -> V_91 ;
} else if ( V_62 == - V_80 ) {
V_62 = - V_5 ;
F_6 ( & V_6 -> V_36 ) ;
F_25 ( V_31 ) ;
F_7 ( & V_6 -> V_36 ) ;
}
if ( V_31 -> V_92 . V_55 == true ) {
V_31 -> V_92 . V_53 = true ;
V_31 -> V_92 . V_54 = V_62 ;
F_17 ( & V_6 -> V_67 ) ;
}
} else {
V_62 = - V_15 ;
F_20 ( L_18 ) ;
}
return V_62 ;
}
int F_31 ( int V_27 )
{
int V_62 = 0 ;
struct V_22 * V_23 = NULL ;
struct V_30 * V_31 ;
F_2 ( L_24 , V_27 ) ;
V_62 = F_23 ( V_27 ) ;
if ( V_62 )
return V_62 ;
V_31 = & V_6 -> V_7 [ V_27 ] ;
if ( V_31 -> V_8 != V_77 &&
V_31 -> V_8 != V_74 &&
V_31 -> V_8 != V_76 ) {
F_20 ( L_25 ,
V_31 -> V_8 ) ;
return - V_15 ;
}
if ( V_31 -> V_8 == V_74 ) {
if ( F_19 ( & V_23 ) ) {
F_20 ( L_21 ) ;
return - V_37 ;
}
F_10 ( & V_23 -> V_38 , V_93 , 0 , V_27 ) ;
F_11 ( & V_6 -> V_56 ) ;
F_12 ( & V_23 -> V_57 , & V_6 -> V_58 ) ;
F_13 ( & V_6 -> V_56 ) ;
F_14 ( & V_6 -> V_59 ) ;
} else
V_31 -> V_94 = true ;
V_31 -> V_92 . V_53 = false ;
V_31 -> V_92 . V_54 = 0 ;
V_31 -> V_92 . V_55 = true ;
V_62 = F_32 ( V_6 , & V_31 -> V_92 ) ;
V_31 -> V_94 = false ;
return V_62 ;
}
int F_33 ( int V_27 )
{
int V_62 = 0 ;
struct V_22 * V_23 = NULL ;
struct V_30 * V_31 ;
F_2 ( L_26 , V_27 ) ;
V_62 = F_23 ( V_27 ) ;
if ( V_62 )
return V_62 ;
V_31 = & V_6 -> V_7 [ V_27 ] ;
if ( V_31 -> V_8 != V_9 ) {
if ( F_19 ( & V_23 ) ) {
F_20 ( L_21 ) ;
return - V_37 ;
}
F_10 ( & V_23 -> V_38 , V_95 , 0 , V_27 ) ;
F_11 ( & V_6 -> V_56 ) ;
F_12 ( & V_23 -> V_57 , & V_6 -> V_58 ) ;
F_13 ( & V_6 -> V_56 ) ;
F_14 ( & V_6 -> V_59 ) ;
V_31 -> V_78 = V_31 -> V_8 ;
V_31 -> V_8 = V_9 ;
if ( V_31 -> V_92 . V_55 == true ) {
V_31 -> V_92 . V_53 = true ;
V_31 -> V_92 . V_54 = 0 ;
F_17 ( & V_6 -> V_67 ) ;
}
V_31 -> V_92 . V_55 = true ;
V_31 -> V_92 . V_53 = false ;
V_62 = F_21 ( V_6 ,
& V_31 -> V_52 , V_72 ) ;
F_2 ( L_27 , V_62 ) ;
F_34 ( 100 ) ;
F_6 ( & V_6 -> V_36 ) ;
F_25 ( V_31 ) ;
F_7 ( & V_6 -> V_36 ) ;
F_2 ( L_28 ) ;
} else {
V_62 = - V_15 ;
F_2 ( L_29 ) ;
}
return V_62 ;
}
