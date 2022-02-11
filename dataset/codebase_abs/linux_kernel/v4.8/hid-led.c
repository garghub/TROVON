static int F_1 ( struct V_1 * V_2 , T_1 * V_3 )
{
int V_4 ;
F_2 ( & V_2 -> V_5 ) ;
if ( V_2 -> V_6 -> V_7 == V_8 )
V_4 = F_3 ( V_2 -> V_9 , V_3 [ 0 ] , V_3 ,
V_2 -> V_6 -> V_10 ,
V_11 ,
V_12 ) ;
else if ( V_2 -> V_6 -> V_7 == V_13 )
V_4 = F_4 ( V_2 -> V_9 , V_3 ,
V_2 -> V_6 -> V_10 ) ;
else
V_4 = - V_14 ;
F_5 ( & V_2 -> V_5 ) ;
if ( V_4 < 0 )
return V_4 ;
return V_4 == V_2 -> V_6 -> V_10 ? 0 : - V_15 ;
}
static int F_6 ( struct V_1 * V_2 , T_1 * V_3 )
{
int V_4 ;
if ( V_2 -> V_6 -> V_7 != V_8 )
return - V_14 ;
F_2 ( & V_2 -> V_5 ) ;
V_4 = F_3 ( V_2 -> V_9 , V_3 [ 0 ] , V_3 ,
V_2 -> V_6 -> V_10 ,
V_11 ,
V_12 ) ;
if ( V_4 < 0 )
goto V_16;
V_4 = F_3 ( V_2 -> V_9 , V_3 [ 0 ] , V_3 ,
V_2 -> V_6 -> V_10 ,
V_11 ,
V_17 ) ;
V_16:
F_5 ( & V_2 -> V_5 ) ;
return V_4 < 0 ? V_4 : 0 ;
}
static T_2 F_7 ( struct V_18 * V_19 )
{
enum V_20 V_21 , V_22 , V_23 ;
V_21 = V_19 -> V_24 . V_25 . V_26 ;
V_22 = V_19 -> V_27 . V_25 . V_26 ;
V_23 = V_19 -> V_28 . V_25 . V_26 ;
if ( V_29 )
return F_8 ( V_21 , V_23 , V_22 ) ;
else
return F_8 ( V_21 , V_22 , V_23 ) ;
}
static int F_9 ( struct V_30 * V_25 , enum V_20 V_31 )
{
struct V_32 * V_33 = F_10 ( V_25 ) ;
struct V_18 * V_19 = V_33 -> V_19 ;
T_1 V_3 [ V_34 ] = {} ;
V_3 [ 1 ] = F_7 ( V_19 ) ;
return F_1 ( V_19 -> V_2 , V_3 ) ;
}
static int F_11 ( struct V_30 * V_25 , enum V_20 V_31 )
{
struct V_32 * V_33 = F_10 ( V_25 ) ;
struct V_18 * V_19 = V_33 -> V_19 ;
T_1 V_3 [ V_34 ] = {} ;
V_3 [ 1 ] = V_19 -> V_24 . V_25 . V_26 ;
V_3 [ 2 ] = V_19 -> V_27 . V_25 . V_26 ;
V_3 [ 3 ] = V_19 -> V_28 . V_25 . V_26 ;
V_3 [ 7 ] = 0x1a ;
V_3 [ 8 ] = 0x05 ;
return F_1 ( V_19 -> V_2 , V_3 ) ;
}
static int F_12 ( struct V_1 * V_2 )
{
T_1 V_3 [ V_34 ] = {} ;
V_3 [ 1 ] = 0x1f ;
V_3 [ 2 ] = 0x02 ;
V_3 [ 4 ] = 0x5f ;
V_3 [ 7 ] = 0x1a ;
V_3 [ 8 ] = 0x03 ;
return F_1 ( V_2 , V_3 ) ;
}
static int F_13 ( struct V_30 * V_25 , enum V_20 V_31 ,
T_2 V_35 )
{
struct V_32 * V_33 = F_10 ( V_25 ) ;
T_1 V_3 [ V_34 ] = { 1 , 'c' } ;
V_3 [ 2 ] = V_33 -> V_19 -> V_24 . V_25 . V_26 ;
V_3 [ 3 ] = V_33 -> V_19 -> V_27 . V_25 . V_26 ;
V_3 [ 4 ] = V_33 -> V_19 -> V_28 . V_25 . V_26 ;
V_3 [ 7 ] = V_33 -> V_19 -> V_36 + V_35 ;
return F_1 ( V_33 -> V_19 -> V_2 , V_3 ) ;
}
static int F_14 ( struct V_30 * V_25 , enum V_20 V_31 )
{
return F_13 ( V_25 , V_31 , 0 ) ;
}
static int F_15 ( struct V_30 * V_25 , enum V_20 V_31 )
{
return F_13 ( V_25 , V_31 , 1 ) ;
}
static int F_16 ( struct V_1 * V_2 )
{
T_1 V_3 [ V_34 ] = { 1 , 'v' } ;
int V_4 ;
V_4 = F_6 ( V_2 , V_3 ) ;
if ( V_4 )
return V_4 ;
if ( V_3 [ 3 ] == '1' )
V_2 -> V_6 = & V_37 ;
return 0 ;
}
static inline int F_17 ( const struct V_32 * V_33 )
{
if ( V_33 == & V_33 -> V_19 -> V_24 )
return V_38 ;
else if ( V_33 == & V_33 -> V_19 -> V_27 )
return V_39 ;
else
return V_40 ;
}
static int F_18 ( struct V_32 * V_33 )
{
union V_41 V_42 = { . V_43 . V_44 = 101 , . V_43 . V_45 = 12 } ;
V_42 . V_43 . V_46 = 1 << F_17 ( V_33 ) ;
V_42 . V_43 . V_47 = 0 ;
return F_1 ( V_33 -> V_19 -> V_2 , V_42 . V_48 ) ;
}
static int F_19 ( struct V_32 * V_33 )
{
union V_41 V_42 = { . V_43 . V_44 = 101 , . V_43 . V_45 = 34 } ;
V_42 . V_43 . V_46 = F_17 ( V_33 ) ;
V_42 . V_43 . V_47 = V_33 -> V_25 . V_26 ;
return F_1 ( V_33 -> V_19 -> V_2 , V_42 . V_48 ) ;
}
static int F_20 ( struct V_30 * V_25 , enum V_20 V_31 )
{
struct V_32 * V_33 = F_10 ( V_25 ) ;
int V_4 ;
V_4 = F_18 ( V_33 ) ;
if ( V_4 )
return V_4 ;
return F_19 ( V_33 ) ;
}
static int F_21 ( struct V_1 * V_2 )
{
union V_41 V_42 = { . V_49 . V_50 = 104 } ;
int V_4 ;
V_4 = F_6 ( V_2 , V_42 . V_48 ) ;
if ( V_4 )
return V_4 ;
return F_22 ( V_42 . V_51 . V_52 ) == 2 ? 0 : - V_53 ;
}
static int F_23 ( struct V_30 * V_25 , enum V_20 V_31 )
{
struct V_32 * V_33 = F_10 ( V_25 ) ;
T_1 V_3 [ V_34 ] = { [ 1 ] = 1 } ;
V_3 [ 2 ] = V_33 -> V_19 -> V_36 + 1 ;
V_3 [ 3 ] = V_33 -> V_19 -> V_24 . V_25 . V_26 ;
V_3 [ 4 ] = V_33 -> V_19 -> V_27 . V_25 . V_26 ;
V_3 [ 5 ] = V_33 -> V_19 -> V_28 . V_25 . V_26 ;
return F_1 ( V_33 -> V_19 -> V_2 , V_3 ) ;
}
static int F_24 ( struct V_32 * V_33 , const char * V_54 ,
struct V_18 * V_19 , unsigned int V_55 )
{
const struct V_56 * V_6 = V_19 -> V_2 -> V_6 ;
if ( V_6 -> V_57 > 1 )
snprintf ( V_33 -> V_58 , sizeof( V_33 -> V_58 ) , L_1 ,
V_6 -> V_59 , V_55 , V_54 , V_19 -> V_36 ) ;
else
snprintf ( V_33 -> V_58 , sizeof( V_33 -> V_58 ) , L_2 ,
V_6 -> V_59 , V_55 , V_54 ) ;
V_33 -> V_25 . V_58 = V_33 -> V_58 ;
V_33 -> V_25 . V_60 = V_6 -> V_60 ;
V_33 -> V_25 . V_61 = V_6 -> V_62 ;
V_33 -> V_25 . V_63 = V_64 ;
V_33 -> V_19 = V_19 ;
return F_25 ( & V_19 -> V_2 -> V_9 -> V_65 , & V_33 -> V_25 ) ;
}
static int F_26 ( struct V_18 * V_19 , unsigned int V_55 )
{
int V_4 ;
V_4 = F_24 ( & V_19 -> V_24 , L_3 , V_19 , V_55 ) ;
if ( V_4 )
return V_4 ;
V_4 = F_24 ( & V_19 -> V_27 , L_4 , V_19 , V_55 ) ;
if ( V_4 )
return V_4 ;
return F_24 ( & V_19 -> V_28 , L_5 , V_19 , V_55 ) ;
}
static int F_27 ( struct V_66 * V_9 , const struct V_67 * V_68 )
{
struct V_1 * V_2 ;
unsigned int V_55 ;
int V_4 , V_69 ;
V_2 = F_28 ( & V_9 -> V_65 , sizeof( * V_2 ) , V_70 ) ;
if ( ! V_2 )
return - V_71 ;
V_4 = F_29 ( V_9 ) ;
if ( V_4 )
return V_4 ;
V_2 -> V_9 = V_9 ;
F_30 ( & V_2 -> V_5 ) ;
for ( V_69 = 0 ; ! V_2 -> V_6 && V_69 < F_31 ( V_72 ) ; V_69 ++ )
if ( V_72 [ V_69 ] . type == V_68 -> V_73 )
V_2 -> V_6 = & V_72 [ V_69 ] ;
if ( ! V_2 -> V_6 )
return - V_14 ;
if ( V_2 -> V_6 -> V_74 ) {
V_4 = V_2 -> V_6 -> V_74 ( V_2 ) ;
if ( V_4 )
return V_4 ;
}
V_2 -> V_19 = F_32 ( & V_9 -> V_65 , V_2 -> V_6 -> V_57 ,
sizeof( struct V_18 ) , V_70 ) ;
if ( ! V_2 -> V_19 )
return - V_71 ;
V_4 = F_33 ( V_9 , V_75 ) ;
if ( V_4 )
return V_4 ;
V_55 = ( (struct V_76 * ) V_9 -> V_76 ) -> V_55 ;
for ( V_69 = 0 ; V_69 < V_2 -> V_6 -> V_57 ; V_69 ++ ) {
V_2 -> V_19 [ V_69 ] . V_2 = V_2 ;
V_2 -> V_19 [ V_69 ] . V_36 = V_69 ;
V_4 = F_26 ( & V_2 -> V_19 [ V_69 ] , V_55 ) ;
if ( V_4 ) {
F_34 ( V_9 ) ;
return V_4 ;
}
}
F_35 ( V_9 , L_6 , V_2 -> V_6 -> V_58 ) ;
return 0 ;
}
