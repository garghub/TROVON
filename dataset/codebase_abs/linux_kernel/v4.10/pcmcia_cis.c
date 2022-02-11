int F_1 ( struct V_1 * V_2 , unsigned int V_3 ,
T_1 V_4 , void * V_5 )
{
T_2 V_6 ;
T_1 * V_7 ;
int V_8 ;
V_7 = F_2 ( 256 , V_9 ) ;
if ( V_7 == NULL ) {
F_3 ( & V_2 -> V_10 , L_1 ) ;
return - V_11 ;
}
V_6 . V_12 = V_4 ;
V_6 . V_13 = 0 ;
if ( V_3 == V_14 )
V_6 . V_13 = V_15 ;
V_8 = F_4 ( V_2 , V_3 , & V_6 ) ;
if ( V_8 != 0 )
goto V_16;
V_6 . V_17 = V_7 ;
V_6 . V_18 = 0 ;
V_6 . V_19 = 255 ;
V_8 = F_5 ( V_2 , & V_6 ) ;
if ( V_8 != 0 )
goto V_16;
V_8 = F_6 ( & V_6 , V_5 ) ;
V_16:
F_7 ( V_7 ) ;
return V_8 ;
}
int F_8 ( struct V_1 * V_2 , unsigned int V_3 ,
T_1 V_4 , T_3 * V_5 , void * V_20 ,
int (* F_9) ( T_2 * V_6 ,
T_3 * V_5 ,
void * V_20 ) )
{
T_2 V_6 ;
T_1 * V_7 ;
int V_8 ;
V_7 = F_10 ( 256 , V_9 ) ;
if ( V_7 == NULL ) {
F_3 ( & V_2 -> V_10 , L_1 ) ;
return - V_11 ;
}
V_6 . V_17 = V_7 ;
V_6 . V_19 = 255 ;
V_6 . V_18 = 0 ;
V_6 . V_12 = V_4 ;
V_6 . V_13 = 0 ;
V_8 = F_4 ( V_2 , V_3 , & V_6 ) ;
while ( ! V_8 ) {
if ( F_5 ( V_2 , & V_6 ) )
goto V_21;
if ( V_5 )
if ( F_6 ( & V_6 , V_5 ) )
goto V_21;
V_8 = F_9 ( & V_6 , V_5 , V_20 ) ;
if ( ! V_8 )
break;
V_21:
V_8 = F_11 ( V_2 , V_3 , & V_6 ) ;
}
F_7 ( V_7 ) ;
return V_8 ;
}
static int F_12 ( unsigned int V_22 )
{
if ( ! ( V_22 & V_23 ) )
return V_24 ;
if ( ! ( V_22 & V_25 ) )
return V_26 ;
return V_27 ;
}
static int F_13 ( T_2 * V_6 , T_3 * V_5 , void * V_28 )
{
struct V_29 * V_30 = V_28 ;
struct V_31 * V_32 = V_30 -> V_32 ;
T_4 * V_33 = & V_5 -> V_34 ;
T_4 * V_35 = & V_30 -> V_35 ;
unsigned int V_22 = V_32 -> V_36 ;
unsigned int V_37 = V_32 -> V_38 -> V_38 . V_39 ;
F_14 ( & V_32 -> V_10 , L_2 ,
V_33 -> V_40 , V_22 ) ;
V_30 -> V_32 -> V_41 = V_33 -> V_40 ;
if ( V_33 -> V_22 & V_42 )
V_30 -> V_35 = * V_33 ;
if ( V_22 & V_43 ) {
if ( V_33 -> V_37 . V_44 & ( 1 << V_45 ) ) {
if ( V_37 != V_33 -> V_37 . V_46 [ V_45 ] / 10000 )
return - V_47 ;
} else if ( V_35 -> V_37 . V_44 & ( 1 << V_45 ) ) {
if ( V_37 != V_35 -> V_37 . V_46 [ V_45 ] / 10000 )
return - V_47 ;
}
}
if ( V_22 & V_48 ) {
if ( V_33 -> V_49 . V_44 & ( 1 << V_45 ) )
V_32 -> V_50 = V_33 -> V_49 . V_46 [ V_45 ] / 10000 ;
else if ( V_35 -> V_49 . V_44 & ( 1 << V_45 ) )
V_32 -> V_50 =
V_35 -> V_49 . V_46 [ V_45 ] / 10000 ;
}
if ( ( V_22 & V_51 ) && ( V_33 -> V_22 & V_52 ) )
V_32 -> V_36 |= V_53 ;
if ( V_22 & V_54 ) {
T_5 * V_55 = ( V_33 -> V_55 . V_56 ) ? & V_33 -> V_55 : & V_35 -> V_55 ;
int V_57 = 0 ;
V_32 -> V_58 [ 0 ] -> V_59 = V_32 -> V_58 [ 0 ] -> V_60 = 0 ;
V_32 -> V_58 [ 1 ] -> V_59 = V_32 -> V_58 [ 1 ] -> V_60 = 0 ;
if ( V_55 -> V_56 == 0 )
return - V_47 ;
V_32 -> V_58 [ 0 ] -> V_22 &= ~ V_61 ;
V_32 -> V_58 [ 0 ] -> V_22 |=
F_12 ( V_55 -> V_22 ) ;
if ( V_55 -> V_56 > 1 ) {
V_57 = ( V_55 -> V_62 [ 1 ] . V_63 > V_55 -> V_62 [ 0 ] . V_63 ) ;
V_32 -> V_58 [ 1 ] -> V_22 = V_32 -> V_58 [ 0 ] -> V_22 ;
V_32 -> V_58 [ 1 ] -> V_59 = V_55 -> V_62 [ 1 - V_57 ] . V_64 ;
V_32 -> V_58 [ 1 ] -> V_60 = V_55 -> V_62 [ 1 - V_57 ] . V_63 ;
}
V_32 -> V_58 [ 0 ] -> V_59 = V_55 -> V_62 [ V_57 ] . V_64 ;
V_32 -> V_58 [ 0 ] -> V_60 = V_55 -> V_62 [ V_57 ] . V_63 ;
V_32 -> V_65 = V_55 -> V_22 & V_66 ;
}
if ( V_22 & V_67 ) {
T_6 * V_68 = ( V_33 -> V_68 . V_56 ) ? & V_33 -> V_68 : & V_35 -> V_68 ;
V_32 -> V_58 [ 2 ] -> V_59 = V_32 -> V_58 [ 2 ] -> V_60 = 0 ;
if ( V_68 -> V_56 == 0 )
return - V_47 ;
V_32 -> V_58 [ 2 ] -> V_59 = V_68 -> V_62 [ 0 ] . V_69 ;
V_32 -> V_58 [ 2 ] -> V_60 = V_68 -> V_62 [ 0 ] . V_63 ;
if ( V_32 -> V_58 [ 2 ] -> V_60 < 0x1000 )
V_32 -> V_58 [ 2 ] -> V_60 = 0x1000 ;
V_32 -> V_70 = V_68 -> V_62 [ 0 ] . V_70 ;
}
F_14 ( & V_32 -> V_10 ,
L_3 ,
V_32 -> V_41 , V_32 -> V_58 [ 0 ] , V_32 -> V_58 [ 1 ] ,
V_32 -> V_58 [ 2 ] , V_32 -> V_65 ) ;
return V_30 -> V_71 ( V_32 , V_30 -> V_20 ) ;
}
int F_15 ( struct V_31 * V_32 ,
int (* V_71) ( struct V_31 * V_32 ,
void * V_20 ) ,
void * V_20 )
{
struct V_29 * V_30 ;
int V_8 ;
V_30 = F_10 ( sizeof( struct V_29 ) , V_9 ) ;
if ( V_30 == NULL )
return - V_11 ;
V_30 -> V_32 = V_32 ;
V_30 -> V_71 = V_71 ;
V_30 -> V_20 = V_20 ;
V_8 = F_8 ( V_32 -> V_38 , V_32 -> V_72 ,
V_73 , & V_30 -> V_5 ,
V_30 , F_13 ) ;
F_7 ( V_30 ) ;
return V_8 ;
}
static int F_16 ( T_2 * V_6 , T_3 * V_5 , void * V_28 )
{
struct V_74 * V_75 = V_28 ;
return V_75 -> F_9 ( V_75 -> V_32 , V_6 , V_75 -> V_20 ) ;
}
int F_17 ( struct V_31 * V_32 , T_1 V_4 ,
int (* F_9) ( struct V_31 * V_32 ,
T_2 * V_6 ,
void * V_20 ) ,
void * V_20 )
{
struct V_74 V_75 = {
. V_32 = V_32 ,
. F_9 = F_9 ,
. V_20 = V_20 } ;
return F_8 ( V_32 -> V_38 , V_32 -> V_72 , V_4 , NULL ,
& V_75 , F_16 ) ;
}
static int F_18 ( struct V_31 * V_32 , T_2 * V_6 ,
void * V_28 )
{
struct V_76 * V_77 = V_28 ;
* V_77 -> V_7 = F_10 ( V_6 -> V_78 , V_9 ) ;
if ( * V_77 -> V_7 ) {
V_77 -> V_63 = V_6 -> V_78 ;
memcpy ( * V_77 -> V_7 , V_6 -> V_17 , V_6 -> V_78 ) ;
} else
F_14 ( & V_32 -> V_10 , L_4 ) ;
return 0 ;
}
T_7 F_19 ( struct V_31 * V_32 , T_1 V_4 ,
unsigned char * * V_7 )
{
struct V_76 V_77 = {
. V_63 = 0 ,
. V_7 = V_7 ,
} ;
* V_77 . V_7 = NULL ;
F_17 ( V_32 , V_4 , F_18 , & V_77 ) ;
return V_77 . V_63 ;
}
static int F_20 ( struct V_31 * V_32 , T_2 * V_6 ,
void * V_28 )
{
struct V_79 * V_10 = V_28 ;
int V_57 ;
if ( V_6 -> V_17 [ 0 ] != V_80 )
return - V_81 ;
if ( V_6 -> V_78 < V_82 + 2 ) {
F_3 ( & V_32 -> V_10 , L_5
L_6 ) ;
return - V_81 ;
}
if ( V_6 -> V_17 [ 1 ] != V_82 ) {
F_3 ( & V_32 -> V_10 , L_7 ) ;
return - V_81 ;
}
for ( V_57 = 0 ; V_57 < 6 ; V_57 ++ )
V_10 -> V_83 [ V_57 ] = V_6 -> V_17 [ V_57 + 2 ] ;
return 0 ;
}
int F_21 ( struct V_31 * V_32 , struct V_79 * V_10 )
{
return F_17 ( V_32 , V_84 , F_20 , V_10 ) ;
}
