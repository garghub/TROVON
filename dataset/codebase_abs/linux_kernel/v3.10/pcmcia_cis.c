int F_1 ( struct V_1 * V_2 , unsigned int V_3 ,
T_1 V_4 , void * V_5 )
{
T_2 V_6 ;
T_1 * V_7 ;
int V_8 ;
V_7 = F_2 ( 256 , V_9 ) ;
if ( V_7 == NULL ) {
F_3 ( V_10 , & V_2 -> V_11 , L_1 ) ;
return - V_12 ;
}
V_6 . V_13 = V_4 ;
V_6 . V_14 = 0 ;
if ( V_3 == V_15 )
V_6 . V_14 = V_16 ;
V_8 = F_4 ( V_2 , V_3 , & V_6 ) ;
if ( V_8 != 0 )
goto V_17;
V_6 . V_18 = V_7 ;
V_6 . V_19 = 0 ;
V_6 . V_20 = 255 ;
V_8 = F_5 ( V_2 , & V_6 ) ;
if ( V_8 != 0 )
goto V_17;
V_8 = F_6 ( & V_6 , V_5 ) ;
V_17:
F_7 ( V_7 ) ;
return V_8 ;
}
int F_8 ( struct V_1 * V_2 , unsigned int V_3 ,
T_1 V_4 , T_3 * V_5 , void * V_21 ,
int (* F_9) ( T_2 * V_6 ,
T_3 * V_5 ,
void * V_21 ) )
{
T_2 V_6 ;
T_1 * V_7 ;
int V_8 ;
V_7 = F_10 ( 256 , V_9 ) ;
if ( V_7 == NULL ) {
F_3 ( V_10 , & V_2 -> V_11 , L_1 ) ;
return - V_12 ;
}
V_6 . V_18 = V_7 ;
V_6 . V_20 = 255 ;
V_6 . V_19 = 0 ;
V_6 . V_13 = V_4 ;
V_6 . V_14 = 0 ;
V_8 = F_4 ( V_2 , V_3 , & V_6 ) ;
while ( ! V_8 ) {
if ( F_5 ( V_2 , & V_6 ) )
goto V_22;
if ( V_5 )
if ( F_6 ( & V_6 , V_5 ) )
goto V_22;
V_8 = F_9 ( & V_6 , V_5 , V_21 ) ;
if ( ! V_8 )
break;
V_22:
V_8 = F_11 ( V_2 , V_3 , & V_6 ) ;
}
F_7 ( V_7 ) ;
return V_8 ;
}
static int F_12 ( unsigned int V_23 )
{
if ( ! ( V_23 & V_24 ) )
return V_25 ;
if ( ! ( V_23 & V_26 ) )
return V_27 ;
return V_28 ;
}
static int F_13 ( T_2 * V_6 , T_3 * V_5 , void * V_29 )
{
struct V_30 * V_31 = V_29 ;
struct V_32 * V_33 = V_31 -> V_33 ;
T_4 * V_34 = & V_5 -> V_35 ;
T_4 * V_36 = & V_31 -> V_36 ;
unsigned int V_23 = V_33 -> V_37 ;
unsigned int V_38 = V_33 -> V_39 -> V_39 . V_40 ;
F_14 ( & V_33 -> V_11 , L_2 ,
V_34 -> V_41 , V_23 ) ;
V_31 -> V_33 -> V_42 = V_34 -> V_41 ;
if ( V_34 -> V_23 & V_43 )
V_31 -> V_36 = * V_34 ;
if ( V_23 & V_44 ) {
if ( V_34 -> V_38 . V_45 & ( 1 << V_46 ) ) {
if ( V_38 != V_34 -> V_38 . V_47 [ V_46 ] / 10000 )
return - V_48 ;
} else if ( V_36 -> V_38 . V_45 & ( 1 << V_46 ) ) {
if ( V_38 != V_36 -> V_38 . V_47 [ V_46 ] / 10000 )
return - V_48 ;
}
}
if ( V_23 & V_49 ) {
if ( V_34 -> V_50 . V_45 & ( 1 << V_46 ) )
V_33 -> V_51 = V_34 -> V_50 . V_47 [ V_46 ] / 10000 ;
else if ( V_36 -> V_50 . V_45 & ( 1 << V_46 ) )
V_33 -> V_51 =
V_36 -> V_50 . V_47 [ V_46 ] / 10000 ;
}
if ( ( V_23 & V_52 ) && ( V_34 -> V_23 & V_53 ) )
V_33 -> V_37 |= V_54 ;
if ( V_23 & V_55 ) {
T_5 * V_56 = ( V_34 -> V_56 . V_57 ) ? & V_34 -> V_56 : & V_36 -> V_56 ;
int V_58 = 0 ;
V_33 -> V_59 [ 0 ] -> V_60 = V_33 -> V_59 [ 0 ] -> V_61 = 0 ;
V_33 -> V_59 [ 1 ] -> V_60 = V_33 -> V_59 [ 1 ] -> V_61 = 0 ;
if ( V_56 -> V_57 == 0 )
return - V_48 ;
V_33 -> V_59 [ 0 ] -> V_23 &= ~ V_62 ;
V_33 -> V_59 [ 0 ] -> V_23 |=
F_12 ( V_56 -> V_23 ) ;
if ( V_56 -> V_57 > 1 ) {
V_58 = ( V_56 -> V_63 [ 1 ] . V_64 > V_56 -> V_63 [ 0 ] . V_64 ) ;
V_33 -> V_59 [ 1 ] -> V_23 = V_33 -> V_59 [ 0 ] -> V_23 ;
V_33 -> V_59 [ 1 ] -> V_60 = V_56 -> V_63 [ 1 - V_58 ] . V_65 ;
V_33 -> V_59 [ 1 ] -> V_61 = V_56 -> V_63 [ 1 - V_58 ] . V_64 ;
}
V_33 -> V_59 [ 0 ] -> V_60 = V_56 -> V_63 [ V_58 ] . V_65 ;
V_33 -> V_59 [ 0 ] -> V_61 = V_56 -> V_63 [ V_58 ] . V_64 ;
V_33 -> V_66 = V_56 -> V_23 & V_67 ;
}
if ( V_23 & V_68 ) {
T_6 * V_69 = ( V_34 -> V_69 . V_57 ) ? & V_34 -> V_69 : & V_36 -> V_69 ;
V_33 -> V_59 [ 2 ] -> V_60 = V_33 -> V_59 [ 2 ] -> V_61 = 0 ;
if ( V_69 -> V_57 == 0 )
return - V_48 ;
V_33 -> V_59 [ 2 ] -> V_60 = V_69 -> V_63 [ 0 ] . V_70 ;
V_33 -> V_59 [ 2 ] -> V_61 = V_69 -> V_63 [ 0 ] . V_64 ;
if ( V_33 -> V_59 [ 2 ] -> V_61 < 0x1000 )
V_33 -> V_59 [ 2 ] -> V_61 = 0x1000 ;
V_33 -> V_71 = V_69 -> V_63 [ 0 ] . V_71 ;
}
F_14 ( & V_33 -> V_11 ,
L_3 ,
V_33 -> V_42 , V_33 -> V_59 [ 0 ] , V_33 -> V_59 [ 1 ] ,
V_33 -> V_59 [ 2 ] , V_33 -> V_66 ) ;
return V_31 -> V_72 ( V_33 , V_31 -> V_21 ) ;
}
int F_15 ( struct V_32 * V_33 ,
int (* V_72) ( struct V_32 * V_33 ,
void * V_21 ) ,
void * V_21 )
{
struct V_30 * V_31 ;
int V_8 ;
V_31 = F_10 ( sizeof( struct V_30 ) , V_9 ) ;
if ( V_31 == NULL )
return - V_12 ;
V_31 -> V_33 = V_33 ;
V_31 -> V_72 = V_72 ;
V_31 -> V_21 = V_21 ;
V_8 = F_8 ( V_33 -> V_39 , V_33 -> V_73 ,
V_74 , & V_31 -> V_5 ,
V_31 , F_13 ) ;
F_7 ( V_31 ) ;
return V_8 ;
}
static int F_16 ( T_2 * V_6 , T_3 * V_5 , void * V_29 )
{
struct V_75 * V_76 = V_29 ;
return V_76 -> F_9 ( V_76 -> V_33 , V_6 , V_76 -> V_21 ) ;
}
int F_17 ( struct V_32 * V_33 , T_1 V_4 ,
int (* F_9) ( struct V_32 * V_33 ,
T_2 * V_6 ,
void * V_21 ) ,
void * V_21 )
{
struct V_75 V_76 = {
. V_33 = V_33 ,
. F_9 = F_9 ,
. V_21 = V_21 } ;
return F_8 ( V_33 -> V_39 , V_33 -> V_73 , V_4 , NULL ,
& V_76 , F_16 ) ;
}
static int F_18 ( struct V_32 * V_33 , T_2 * V_6 ,
void * V_29 )
{
struct V_77 * V_78 = V_29 ;
* V_78 -> V_7 = F_10 ( V_6 -> V_79 , V_9 ) ;
if ( * V_78 -> V_7 ) {
V_78 -> V_64 = V_6 -> V_79 ;
memcpy ( * V_78 -> V_7 , V_6 -> V_18 , V_6 -> V_79 ) ;
} else
F_14 ( & V_33 -> V_11 , L_4 ) ;
return 0 ;
}
T_7 F_19 ( struct V_32 * V_33 , T_1 V_4 ,
unsigned char * * V_7 )
{
struct V_77 V_78 = {
. V_64 = 0 ,
. V_7 = V_7 ,
} ;
* V_78 . V_7 = NULL ;
F_17 ( V_33 , V_4 , F_18 , & V_78 ) ;
return V_78 . V_64 ;
}
static int F_20 ( struct V_32 * V_33 , T_2 * V_6 ,
void * V_29 )
{
struct V_80 * V_11 = V_29 ;
int V_58 ;
if ( V_6 -> V_18 [ 0 ] != V_81 )
return - V_82 ;
if ( V_6 -> V_79 < V_83 + 2 ) {
F_21 ( & V_33 -> V_11 , L_5
L_6 ) ;
return - V_82 ;
}
if ( V_6 -> V_18 [ 1 ] != V_83 ) {
F_21 ( & V_33 -> V_11 , L_7 ) ;
return - V_82 ;
}
for ( V_58 = 0 ; V_58 < 6 ; V_58 ++ )
V_11 -> V_84 [ V_58 ] = V_6 -> V_18 [ V_58 + 2 ] ;
return 0 ;
}
int F_22 ( struct V_32 * V_33 , struct V_80 * V_11 )
{
return F_17 ( V_33 , V_85 , F_20 , V_11 ) ;
}
