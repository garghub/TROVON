static int F_1 ( struct V_1 * V_2 , T_1 * V_3 )
{
struct V_4 * V_5 ;
struct V_6 * V_7 ;
struct V_3 * V_8 ;
char V_9 ;
int V_10 = 0 ;
F_2 ( L_1 , V_2 -> V_11 ) ;
V_9 = V_12 ;
V_5 = F_3 ( V_2 , V_13 , V_14 ,
& V_9 , V_15 , V_16 ) ;
if ( F_4 ( V_5 ) ) {
V_10 = F_5 ( V_5 ) ;
F_6 ( L_2 , V_2 -> V_11 ,
V_10 ) ;
return V_10 ;
}
if ( V_5 -> V_17 != sizeof( * V_7 ) + sizeof( * V_8 ) ) {
F_6 ( L_3 , V_2 -> V_11 ,
V_5 -> V_17 ) ;
V_10 = - V_18 ;
goto V_19;
}
V_7 = (struct V_6 * ) ( V_5 -> V_20 ) ;
if ( ! V_7 ) {
F_6 ( L_4 , V_2 -> V_11 ) ;
V_10 = - V_18 ;
goto V_19;
}
if ( V_7 -> V_21 != V_22 ||
V_7 -> V_23 != V_24 ) {
F_6 ( L_5 , V_2 -> V_11 ,
V_7 -> V_21 , V_7 -> V_23 ) ;
V_10 = - V_25 ;
goto V_19;
}
V_8 = (struct V_3 * ) ( V_7 -> V_20 ) ;
F_2 ( L_6 , V_2 -> V_11 , F_7 ( V_8 -> V_26 ) ) ;
F_2 ( L_7 , V_2 -> V_11 , F_8 ( V_8 -> V_27 ) ) ;
F_2 ( L_8 , V_2 -> V_11 , F_8 ( V_8 -> V_28 ) ) ;
F_2 ( L_9 , V_2 -> V_11 , F_7 ( V_8 -> V_29 ) ) ;
* V_3 = ( F_7 ( V_8 -> V_29 ) << 16 ) |
( F_8 ( V_8 -> V_28 ) & 0x0000ffff ) ;
V_19:
F_9 ( V_5 ) ;
return V_10 ;
}
static int F_10 ( struct V_1 * V_2 )
{
struct V_4 * V_5 ;
int V_10 ;
F_2 ( L_10 , V_2 -> V_11 ) ;
V_5 = F_11 ( V_2 , V_30 , 0 , NULL , V_16 ) ;
if ( F_4 ( V_5 ) ) {
V_10 = F_5 ( V_5 ) ;
F_6 ( L_11 , V_2 -> V_11 , V_10 ) ;
return V_10 ;
}
F_9 ( V_5 ) ;
return 0 ;
}
static void F_12 ( struct V_31 * V_32 ,
const struct V_33 * V_34 )
{
const T_2 * V_20 ;
T_1 V_35 ;
T_3 V_36 , V_37 ;
int V_38 , V_39 ;
struct V_40 * V_41 ;
struct V_42 * V_43 ;
struct V_44 * V_45 ;
V_41 = (struct V_40 * ) V_34 -> V_20 ;
V_35 = F_7 ( V_41 -> V_35 ) ;
V_39 = ( V_35 >> 8 ) & 0x00ffffff ;
F_2 ( L_12 , V_35 & 0x000000ff ) ;
F_2 ( L_13 , V_39 ) ;
switch ( V_32 -> type ) {
case V_46 :
V_43 = (struct V_42 * ) V_41 -> V_20 ;
F_2 ( L_14 ,
F_7 ( V_43 -> V_47 ) ) ;
F_2 ( L_15 ,
F_7 ( V_43 -> V_48 ) ) ;
F_2 ( L_16 ,
V_43 -> V_49 ) ;
F_2 ( L_17 ,
V_43 -> V_50 ) ;
F_2 ( L_18 ,
F_8 ( V_43 -> V_51 ) ) ;
F_2 ( L_19 ,
F_8 ( V_43 -> V_26 ) ) ;
F_2 ( L_20 ,
F_8 ( V_43 -> V_52 ) ) ;
F_2 ( L_21 ,
F_8 ( V_43 -> V_53 ) ) ;
F_2 ( L_18 ,
F_8 ( V_43 -> V_54 ) ) ;
F_2 ( L_22 ,
F_7 ( V_43 -> V_55 ) ) ;
break;
case V_56 :
V_38 = 0 ;
V_20 = V_41 -> V_20 ;
while ( V_38 < V_39 ) {
V_45 = (struct V_44 * ) ( V_20 + V_38 ) ;
V_36 = F_8 ( V_45 -> V_36 ) ;
V_37 = F_8 ( V_45 -> V_37 ) ;
switch ( V_36 ) {
case V_57 :
V_45 -> V_20 [ 0 ] |= 0x80 ;
V_45 -> V_20 [ 2 ] = V_32 -> V_58 ;
break;
case V_59 :
V_45 -> V_20 [ 0 ] |= 0x01 ;
break;
}
V_38 += ( sizeof( T_3 ) + sizeof( T_3 ) + 8 + V_37 ) ;
}
break;
default:
F_6 ( L_23 , V_32 -> type ) ;
break;
}
}
static int F_13 ( struct V_1 * V_2 , int V_38 , int V_60 ,
const T_2 * V_20 )
{
struct V_4 * V_5 ;
struct V_6 * V_7 ;
struct V_61 * V_62 ;
T_2 V_9 [ V_63 + 2 ] ;
int V_10 = 0 ;
F_2 ( L_24 , V_2 -> V_11 , V_38 , V_60 ) ;
V_9 [ 0 ] = V_64 ;
V_9 [ 1 ] = V_60 ;
memcpy ( V_9 + 2 , V_20 , V_60 ) ;
V_5 = F_3 ( V_2 , V_13 , V_60 + 2 , V_9 ,
V_15 , V_16 ) ;
if ( F_4 ( V_5 ) ) {
V_10 = F_5 ( V_5 ) ;
F_6 ( L_25 , V_2 -> V_11 , V_10 ) ;
return V_10 ;
}
if ( V_5 -> V_17 != sizeof( * V_7 ) + sizeof( * V_62 ) ) {
F_6 ( L_26 , V_2 -> V_11 ) ;
V_10 = - V_18 ;
goto V_19;
}
V_7 = (struct V_6 * ) ( V_5 -> V_20 ) ;
if ( ! V_7 ) {
F_6 ( L_4 , V_2 -> V_11 ) ;
V_10 = - V_18 ;
goto V_19;
}
V_62 = (struct V_61 * ) ( V_7 -> V_20 ) ;
if ( V_7 -> V_21 != V_22 ||
V_7 -> V_23 != V_65 || V_62 -> V_66 != 0x00 ) {
F_6 ( L_27 ,
V_2 -> V_11 , V_7 -> V_21 , V_7 -> V_23 , V_62 -> V_66 ) ;
V_10 = - V_25 ;
}
V_19:
F_9 ( V_5 ) ;
return V_10 ;
}
static int F_14 ( struct V_1 * V_2 ,
const struct V_33 * V_34 )
{
const T_2 * V_67 , * V_20 ;
int V_68 , V_69 ;
int V_70 , V_71 ;
if ( ! V_34 || ! V_34 -> V_20 )
return - V_72 ;
V_68 = V_34 -> V_73 / V_63 ;
V_69 = V_34 -> V_73 % V_63 ;
F_2 ( L_28 ,
V_2 -> V_11 , V_68 , V_69 , V_34 -> V_73 ) ;
V_20 = V_34 -> V_20 ;
for ( V_71 = 0 ; V_71 < V_68 ; V_71 ++ ) {
V_67 = V_20 + V_71 * V_63 ;
V_70 = F_13 ( V_2 , V_71 , V_63 ,
V_67 ) ;
if ( V_70 < 0 )
return - V_25 ;
}
if ( V_69 ) {
V_67 = V_20 + V_68 * V_63 ;
V_70 = F_13 ( V_2 , V_68 , V_69 ,
V_67 ) ;
if ( V_70 < 0 )
return - V_25 ;
}
return 0 ;
}
static int F_15 ( struct V_1 * V_2 ,
struct V_31 * V_32 )
{
const struct V_33 * V_34 ;
int V_70 ;
F_16 ( L_29 , V_2 -> V_11 , V_32 -> V_74 ) ;
V_70 = F_17 ( & V_34 , V_32 -> V_74 , & V_2 -> V_75 ) ;
if ( V_70 ) {
F_6 ( L_30 , V_2 -> V_11 ,
V_32 -> V_74 , V_70 ) ;
return V_70 ;
}
F_12 ( V_32 , V_34 ) ;
V_70 = F_14 ( V_2 , V_34 ) ;
if ( V_70 ) {
F_6 ( L_31 , V_2 -> V_11 ,
V_32 -> V_74 , V_70 ) ;
}
F_18 ( V_34 ) ;
return V_70 ;
}
int F_19 ( struct V_1 * V_2 , const T_4 * V_76 )
{
struct V_4 * V_5 ;
T_2 V_9 [ 9 ] ;
int V_10 ;
V_9 [ 0 ] = V_77 ;
V_9 [ 1 ] = 0x02 ;
V_9 [ 2 ] = sizeof( T_4 ) ;
memcpy ( V_9 + 3 , V_76 , sizeof( T_4 ) ) ;
V_5 = F_3 ( V_2 , V_78 , sizeof( V_9 ) , V_9 ,
V_15 , V_16 ) ;
if ( F_4 ( V_5 ) ) {
V_10 = F_5 ( V_5 ) ;
F_6 ( L_32 ,
V_2 -> V_11 , V_10 ) ;
return V_10 ;
}
F_9 ( V_5 ) ;
return 0 ;
}
int F_20 ( struct V_1 * V_2 , T_5 V_79 )
{
T_1 V_28 = 0 ;
struct V_31 V_32 ;
int V_10 ;
F_2 ( L_33 , V_2 -> V_11 ) ;
V_32 . V_58 = V_79 ;
V_10 = F_1 ( V_2 , & V_28 ) ;
if ( V_10 < 0 || V_28 == 0 ) {
F_6 ( L_34 , V_2 -> V_11 , V_10 ) ;
return V_10 ;
}
F_16 ( L_35 , V_2 -> V_11 , V_28 ) ;
V_32 . type = V_46 ;
snprintf ( V_32 . V_74 , sizeof( V_32 . V_74 ) , L_36 ,
V_28 ) ;
V_10 = F_15 ( V_2 , & V_32 ) ;
if ( V_10 < 0 ) {
F_6 ( L_37 , V_2 -> V_11 , V_10 ) ;
return V_10 ;
}
V_32 . type = V_56 ;
snprintf ( V_32 . V_74 , sizeof( V_32 . V_74 ) , L_38 ,
V_28 ) ;
V_10 = F_15 ( V_2 , & V_32 ) ;
if ( V_10 < 0 ) {
F_6 ( L_39 , V_2 -> V_11 , V_10 ) ;
return V_10 ;
}
V_10 = F_10 ( V_2 ) ;
if ( V_10 < 0 ) {
F_6 ( L_40 , V_2 -> V_11 , V_10 ) ;
return V_10 ;
}
F_16 ( L_41 , V_2 -> V_11 ) ;
return 0 ;
}
