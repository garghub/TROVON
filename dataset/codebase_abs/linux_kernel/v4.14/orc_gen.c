int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
F_2 (file, insn) {
struct V_5 * V_6 = & V_4 -> V_6 ;
struct V_7 * V_8 = & V_4 -> V_9 . V_8 ;
struct V_7 * V_10 = & V_4 -> V_9 . V_11 [ V_12 ] ;
if ( V_8 -> V_13 == V_14 ) {
V_6 -> V_15 = V_16 ;
continue;
}
switch ( V_8 -> V_13 ) {
case V_17 :
V_6 -> V_15 = V_18 ;
break;
case V_19 :
V_6 -> V_15 = V_20 ;
break;
case V_12 :
V_6 -> V_15 = V_21 ;
break;
case V_22 :
V_6 -> V_15 = V_23 ;
break;
case V_24 :
V_6 -> V_15 = V_25 ;
break;
case V_26 :
V_6 -> V_15 = V_27 ;
break;
case V_28 :
V_6 -> V_15 = V_29 ;
break;
case V_30 :
V_6 -> V_15 = V_31 ;
break;
default:
F_3 ( L_1 ,
V_4 -> V_32 , V_4 -> V_33 , V_8 -> V_13 ) ;
return - 1 ;
}
switch( V_10 -> V_13 ) {
case V_14 :
V_6 -> V_34 = V_16 ;
break;
case V_35 :
V_6 -> V_34 = V_36 ;
break;
case V_12 :
V_6 -> V_34 = V_21 ;
break;
default:
F_3 ( L_2 ,
V_4 -> V_32 , V_4 -> V_33 , V_10 -> V_13 ) ;
return - 1 ;
}
V_6 -> V_37 = V_8 -> V_33 ;
V_6 -> V_38 = V_10 -> V_33 ;
V_6 -> type = V_4 -> V_9 . type ;
}
return 0 ;
}
static int F_4 ( struct V_39 * V_40 , struct V_39 * V_41 ,
unsigned int V_42 , struct V_39 * V_43 ,
unsigned long V_44 , struct V_5 * V_45 )
{
struct V_5 * V_6 ;
struct V_46 * V_46 ;
V_6 = (struct V_5 * ) V_40 -> V_47 -> V_48 + V_42 ;
memcpy ( V_6 , V_45 , sizeof( * V_6 ) ) ;
V_46 = malloc ( sizeof( * V_46 ) ) ;
if ( ! V_46 ) {
perror ( L_3 ) ;
return - 1 ;
}
memset ( V_46 , 0 , sizeof( * V_46 ) ) ;
V_46 -> V_49 = V_43 -> V_49 ;
V_46 -> V_50 = V_44 ;
V_46 -> type = V_51 ;
V_46 -> V_33 = V_42 * sizeof( int ) ;
F_5 ( & V_46 -> V_52 , & V_41 -> V_53 ) ;
F_6 ( V_41 -> V_54 , & V_46 -> V_55 , V_46 -> V_33 ) ;
return 0 ;
}
int F_7 ( struct V_1 * V_2 )
{
struct V_3 * V_4 , * V_56 ;
struct V_39 * V_32 , * V_40 , * V_41 ;
unsigned int V_42 ;
struct V_5 V_57 = {
. V_15 = V_16 ,
. V_34 = V_16 ,
. type = V_58 ,
} ;
V_32 = F_8 ( V_2 -> V_59 , L_4 ) ;
if ( V_32 ) {
F_9 ( L_5 ) ;
return - 1 ;
}
V_42 = 0 ;
F_10 (file, sec) {
if ( ! V_32 -> V_60 )
continue;
V_56 = NULL ;
F_11 (file, sec, insn) {
if ( ! V_56 ||
memcmp ( & V_4 -> V_6 , & V_56 -> V_6 ,
sizeof( struct V_5 ) ) ) {
V_42 ++ ;
}
V_56 = V_4 ;
}
if ( V_56 )
V_42 ++ ;
}
if ( ! V_42 )
return - 1 ;
V_32 = F_12 ( V_2 -> V_59 , L_6 , sizeof( int ) , V_42 ) ;
V_41 = F_13 ( V_2 -> V_59 , V_32 ) ;
if ( ! V_41 )
return - 1 ;
V_40 = F_12 ( V_2 -> V_59 , L_4 ,
sizeof( struct V_5 ) , V_42 ) ;
V_42 = 0 ;
F_10 (file, sec) {
if ( ! V_32 -> V_60 )
continue;
V_56 = NULL ;
F_11 (file, sec, insn) {
if ( ! V_56 || memcmp ( & V_4 -> V_6 , & V_56 -> V_6 ,
sizeof( struct V_5 ) ) ) {
if ( F_4 ( V_40 , V_41 , V_42 ,
V_4 -> V_32 , V_4 -> V_33 ,
& V_4 -> V_6 ) )
return - 1 ;
V_42 ++ ;
}
V_56 = V_4 ;
}
if ( V_56 ) {
if ( F_4 ( V_40 , V_41 , V_42 ,
V_56 -> V_32 ,
V_56 -> V_33 + V_56 -> V_61 ,
& V_57 ) )
return - 1 ;
V_42 ++ ;
}
}
if ( F_14 ( V_41 ) )
return - 1 ;
return 0 ;
}
