static T_1 F_1 ( struct V_1 * V_1 , char T_2 * V_2 ,
T_3 V_3 , T_4 * V_4 )
{
struct V_5 * V_6 = V_1 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_9 ;
struct V_10 * V_11 ;
T_1 V_12 = 0 , V_13 ;
F_2 ( V_14 , V_15 ) ;
F_3 ( & V_9 -> V_16 ) ;
if ( V_6 -> V_17 == V_9 -> V_18 ) {
F_4 ( & V_9 -> V_14 , & V_14 ) ;
F_5 ( V_19 ) ;
while ( V_6 -> V_17 == V_9 -> V_18 ) {
if ( V_1 -> V_20 & V_21 ) {
V_12 = - V_22 ;
break;
}
if ( F_6 ( V_15 ) ) {
V_12 = - V_23 ;
break;
}
if ( ! V_9 -> V_24 ) {
V_12 = - V_25 ;
break;
}
F_7 ( & V_9 -> V_16 ) ;
F_8 () ;
F_3 ( & V_9 -> V_16 ) ;
F_5 ( V_19 ) ;
}
F_5 ( V_26 ) ;
F_9 ( & V_9 -> V_14 , & V_14 ) ;
}
if ( V_12 )
goto V_27;
V_11 = & V_9 -> V_28 [ V_6 -> V_17 ] ;
V_13 = V_9 -> V_29 > V_3 ? V_3 : V_9 -> V_29 ;
if ( F_10 ( V_2 , V_11 -> V_30 , V_13 ) ) {
V_12 = - V_31 ;
goto V_27;
}
V_12 += V_13 ;
V_6 -> V_17 = ( V_6 -> V_17 + 1 ) % V_32 ;
V_27:
F_7 ( & V_9 -> V_16 ) ;
return V_12 ;
}
static unsigned int F_11 ( struct V_1 * V_1 , T_5 * V_14 )
{
struct V_5 * V_6 = V_1 -> V_7 ;
F_12 ( V_1 , & V_6 -> V_9 -> V_14 , V_14 ) ;
if ( V_6 -> V_17 != V_6 -> V_9 -> V_18 )
return V_33 | V_34 ;
if ( ! V_6 -> V_9 -> V_24 )
return V_35 | V_36 ;
return 0 ;
}
static int F_13 ( struct V_37 * V_37 , struct V_1 * V_1 )
{
unsigned int V_38 = F_14 ( V_37 ) ;
struct V_5 * V_6 ;
struct V_8 * V_9 ;
int error = 0 ;
V_6 = F_15 ( sizeof( struct V_5 ) , V_39 ) ;
if ( ! V_6 )
return - V_40 ;
F_3 ( & V_41 ) ;
V_9 = V_42 [ V_38 ] ;
F_3 ( & V_9 -> V_43 ) ;
if ( ! V_9 ) {
F_16 ( L_1 , V_38 ) ;
error = - V_44 ;
goto V_45;
}
if ( ! V_9 -> V_46 ++ ) {
error = F_17 ( V_9 -> V_47 , V_48 ) ;
if ( error < 0 ) {
-- V_9 -> V_46 ;
goto V_45;
}
error = F_18 ( V_9 -> V_47 ) ;
if ( error < 0 ) {
F_17 ( V_9 -> V_47 , V_49 ) ;
-- V_9 -> V_46 ;
goto V_45;
}
}
V_6 -> V_9 = V_9 ;
V_6 -> V_17 = V_9 -> V_18 ;
F_19 ( & V_6 -> V_50 , & V_9 -> V_51 ) ;
V_1 -> V_7 = V_6 ;
V_27:
F_7 ( & V_9 -> V_43 ) ;
F_7 ( & V_41 ) ;
return error ;
V_45:
F_20 ( V_6 ) ;
goto V_27;
}
static int F_21 ( struct V_37 * V_37 , struct V_1 * V_1 )
{
unsigned int V_38 = F_14 ( V_37 ) ;
struct V_5 * V_6 = V_1 -> V_7 ;
struct V_8 * V_9 ;
F_3 ( & V_41 ) ;
V_9 = V_42 [ V_38 ] ;
if ( ! V_9 ) {
F_7 ( & V_41 ) ;
F_16 ( L_1 , V_38 ) ;
return - V_44 ;
}
F_3 ( & V_9 -> V_43 ) ;
F_22 ( & V_6 -> V_50 ) ;
F_7 ( & V_9 -> V_43 ) ;
F_20 ( V_6 ) ;
if ( ! -- V_9 -> V_46 ) {
if ( V_9 -> V_24 ) {
F_17 ( V_9 -> V_47 , V_49 ) ;
F_23 ( V_9 -> V_47 ) ;
} else {
F_20 ( V_9 ) ;
}
}
F_7 ( & V_41 ) ;
return 0 ;
}
int F_24 ( int V_38 , T_6 const * V_52 )
{
struct V_8 * V_9 ;
struct V_5 * V_6 ;
struct V_10 * V_11 ;
T_7 * V_53 ;
V_9 = V_42 [ V_38 ] ;
V_53 = F_25 ( V_52 , V_9 -> V_29 , V_54 ) ;
if ( ! V_53 )
return - V_40 ;
V_11 = & V_9 -> V_28 [ V_9 -> V_18 ] ;
F_20 ( V_11 -> V_30 ) ;
V_11 -> V_30 = V_53 ;
V_9 -> V_18 = ( V_9 -> V_18 + 1 ) % V_32 ;
F_26 (reader, &device->readers, node) {
if ( V_6 -> V_17 == V_9 -> V_18 )
V_6 -> V_17 = ( V_6 -> V_17 + 1 ) % V_32 ;
}
F_27 ( & V_9 -> V_14 ) ;
return 0 ;
}
int F_28 ( struct V_55 * V_56 , struct V_57 * V_47 , int V_29 )
{
unsigned int V_38 ;
struct V_8 * V_9 ;
int V_58 ;
V_9 = F_15 ( sizeof( struct V_8 ) , V_39 ) ;
if ( ! V_9 )
return - V_40 ;
F_3 ( & V_41 ) ;
for ( V_38 = 0 ; V_38 < V_59 ; ++ V_38 ) {
if ( V_42 [ V_38 ] )
continue;
break;
}
if ( V_38 < V_59 ) {
V_42 [ V_38 ] = V_9 ;
} else {
F_7 ( & V_41 ) ;
F_20 ( V_9 ) ;
return - V_60 ;
}
V_9 -> V_61 = F_29 ( V_56 , & V_47 -> V_61 ,
F_30 ( V_62 , V_38 ) , NULL ,
L_2 , L_3 , V_47 -> V_63 -> V_64 , V_38 ) ;
if ( F_31 ( V_9 -> V_61 ) ) {
V_42 [ V_38 ] = NULL ;
F_7 ( & V_41 ) ;
V_58 = F_32 ( V_9 -> V_61 ) ;
F_20 ( V_9 ) ;
return V_58 ;
}
F_7 ( & V_41 ) ;
F_33 ( & V_9 -> V_14 ) ;
F_34 ( & V_9 -> V_51 ) ;
F_35 ( & V_9 -> V_43 ) ;
F_35 ( & V_9 -> V_16 ) ;
V_9 -> V_38 = V_38 ;
V_9 -> V_47 = V_47 ;
V_9 -> V_24 = 1 ;
V_9 -> V_18 = 0 ;
V_9 -> V_29 = V_29 ;
return V_38 ;
}
void F_36 ( int V_38 )
{
struct V_8 * V_9 ;
F_3 ( & V_41 ) ;
V_9 = V_42 [ V_38 ] ;
F_7 ( & V_41 ) ;
V_9 -> V_24 = 0 ;
F_37 ( V_9 -> V_61 -> V_55 , F_30 ( V_62 , V_38 ) ) ;
F_3 ( & V_41 ) ;
V_42 [ V_38 ] = NULL ;
F_7 ( & V_41 ) ;
if ( V_9 -> V_46 ) {
F_23 ( V_9 -> V_47 ) ;
F_27 ( & V_9 -> V_14 ) ;
} else {
F_20 ( V_9 ) ;
}
}
static long F_38 ( struct V_1 * V_1 , unsigned int V_65 , unsigned long V_66 )
{
struct V_37 * V_37 = V_1 -> V_67 . V_68 -> V_69 ;
struct V_8 * V_9 ;
unsigned int V_38 = F_14 ( V_37 ) ;
long V_12 = 0 ;
F_3 ( & V_41 ) ;
V_9 = V_42 [ V_38 ] ;
if ( ! V_9 ) {
V_12 = - V_44 ;
goto V_70;
}
switch ( V_65 ) {
case V_71 :
if ( F_39 ( V_9 -> V_29 , ( int T_2 * ) V_66 ) )
V_12 = - V_31 ;
break;
default:
V_12 = - V_72 ;
}
V_70:
F_7 ( & V_41 ) ;
return V_12 ;
}
static int T_8 F_40 ( void )
{
int V_12 ;
T_9 V_73 ;
V_12 = F_41 ( & V_73 , V_74 ,
V_59 , L_3 ) ;
V_62 = F_42 ( V_73 ) ;
if ( V_12 < 0 ) {
F_43 ( L_4 ) ;
return V_12 ;
}
F_44 ( & V_75 , & V_76 ) ;
F_45 ( & V_75 , V_73 , V_59 ) ;
return 0 ;
}
static void T_10 F_46 ( void )
{
T_9 V_73 = F_30 ( V_62 , 0 ) ;
F_47 ( & V_75 ) ;
F_48 ( V_73 , V_59 ) ;
}
