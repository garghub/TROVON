static int F_1 ( struct V_1 * V_2 )
{
int error = F_2 ( V_2 ) ;
if ( error )
return error ;
if ( V_2 -> V_3 == V_4 )
V_5 . V_6 = 1 ;
if ( V_2 -> V_3 == V_7 )
V_5 . V_8 = 1 ;
return 0 ;
}
static int F_3 ( struct V_1 * V_2 )
{
int error ;
if ( V_2 -> V_3 == V_7
&& V_5 . V_8
&& V_5 . V_6 ) {
V_5 . V_9 = V_2 ;
return 0 ;
}
error = F_4 ( V_2 ) ;
if ( error )
return error ;
if ( V_2 -> V_3 == V_7 )
V_5 . V_8 = 0 ;
if ( V_2 -> V_3 == V_4 ) {
V_5 . V_6 = 0 ;
if ( V_5 . V_9 ) {
F_4 ( V_5 . V_9 ) ;
V_5 . V_8 = 0 ;
V_5 . V_9 = NULL ;
}
}
return 0 ;
}
static int F_5 ( struct V_10 * V_11 )
{
int V_12 , error ;
unsigned int V_13 ;
unsigned long V_14 ;
if ( V_11 -> V_2 . V_3 == V_15 ) {
V_11 -> V_16 = 1 ;
return 0 ;
}
error = - V_17 ;
for ( V_13 = 0 ; V_13 < V_11 -> V_18 ; V_13 ++ ) {
F_6 ( & V_11 -> V_2 . V_19 ,
L_1 ,
V_20 , __LINE__ , V_13 ) ;
V_11 -> V_21 = V_13 ;
V_12 = F_7 ( V_11 , V_11 -> V_22 , 0 , 1 ,
0 ) ;
if ( V_12 ) {
F_6 ( & V_11 -> V_2 . V_19 , L_2
L_3 , V_20 ,
__LINE__ , V_13 ) ;
continue;
}
F_6 ( & V_11 -> V_2 . V_19 , L_4 ,
V_20 , __LINE__ , V_13 ) ;
F_8 ( V_13 , & V_11 -> V_16 ) ;
error = 0 ;
}
if ( error )
return error ;
V_14 = F_9 ( V_11 -> V_16 ) ;
if ( V_14 > 1 )
F_10 ( & V_11 -> V_2 . V_19 ,
L_5
L_6 ,
V_20 , __LINE__ , V_14 ) ;
V_11 -> V_21 = F_11 ( V_11 -> V_16 ) ;
F_10 ( & V_11 -> V_2 . V_19 ,
L_7 ,
V_11 -> V_21 , V_11 -> V_23 [ V_11 -> V_21 ] . V_24 ,
V_11 -> V_23 [ V_11 -> V_21 ] . V_25 ) ;
return 0 ;
}
int F_12 ( struct V_10 * V_11 , T_1 V_26 )
{
int error , V_12 , V_27 ;
enum V_28 V_29 ;
error = F_1 ( & V_11 -> V_2 ) ;
if ( error ) {
F_13 ( & V_11 -> V_2 . V_19 ,
L_8 , V_20 ,
__LINE__ , error ) ;
goto V_30;
}
error = F_14 ( & V_11 -> V_2 , V_31 ,
& V_11 -> V_32 ) ;
if ( error ) {
F_13 ( & V_11 -> V_2 . V_19 ,
L_9 ,
V_20 , __LINE__ , error ) ;
goto V_33;
}
error = F_15 ( V_11 -> V_32 , V_26 , V_34 ,
V_11 -> V_2 . V_19 . V_35 -> V_36 , V_11 ) ;
if ( error ) {
F_13 ( & V_11 -> V_2 . V_19 , L_10 ,
V_20 , __LINE__ , error ) ;
goto V_37;
}
V_27 = F_16 ( F_11 ( V_11 -> V_38 ) ,
F_11 ( ( unsigned long ) V_11 -> V_39 ) ) ;
if ( V_27 < 12 ) {
F_13 ( & V_11 -> V_2 . V_19 ,
L_11 ,
V_20 , __LINE__ , V_11 -> V_38 , V_11 -> V_39 ) ;
error = - V_40 ;
goto V_41;
} else if ( V_27 < 16 )
V_29 = V_42 ;
else
V_29 = V_43 ;
V_11 -> V_2 . V_44 = & V_11 -> V_45 ;
F_17 ( & V_11 -> V_2 , & V_11 -> V_45 , V_29 ,
V_46 , V_11 -> V_39 , V_11 -> V_38 ) ;
V_12 = F_18 ( & V_11 -> V_45 ) ;
if ( V_12 ) {
F_13 ( & V_11 -> V_2 . V_19 , L_12 ,
V_20 , __LINE__ ) ;
error = - V_47 ;
goto V_41;
}
V_11 -> V_22 = F_19 ( F_20 ( V_11 -> V_39 ) ) ;
V_11 -> V_48 = F_21 ( & V_11 -> V_2 . V_19 , V_11 -> V_39 ,
V_11 -> V_38 , V_49 ) ;
if ( ! V_11 -> V_48 ) {
F_13 ( & V_11 -> V_2 . V_19 , L_13 ,
V_20 , __LINE__ ) ;
error = - V_50 ;
goto V_51;
}
error = F_5 ( V_11 ) ;
if ( error ) {
F_13 ( & V_11 -> V_2 . V_19 , L_14 ,
V_20 , __LINE__ ) ;
goto V_52;
}
return 0 ;
V_52:
F_22 ( & V_11 -> V_2 . V_19 , V_11 -> V_48 , V_11 -> V_38 ,
V_49 ) ;
V_51:
F_23 ( & V_11 -> V_45 ) ;
V_41:
F_24 ( V_11 -> V_32 , V_11 ) ;
V_37:
F_25 ( & V_11 -> V_2 , V_11 -> V_32 ) ;
V_33:
F_3 ( & V_11 -> V_2 ) ;
V_30:
return error ;
}
void F_26 ( struct V_10 * V_11 )
{
int error ;
F_22 ( & V_11 -> V_2 . V_19 , V_11 -> V_48 , V_11 -> V_38 ,
V_49 ) ;
F_23 ( & V_11 -> V_45 ) ;
F_24 ( V_11 -> V_32 , V_11 ) ;
error = F_25 ( & V_11 -> V_2 , V_11 -> V_32 ) ;
if ( error )
F_13 ( & V_11 -> V_2 . V_19 ,
L_15 ,
V_20 , __LINE__ , error ) ;
error = F_3 ( & V_11 -> V_2 ) ;
if ( error )
F_13 ( & V_11 -> V_2 . V_19 ,
L_16 , V_20 ,
__LINE__ , error ) ;
}
T_2 F_7 ( struct V_10 * V_11 , T_2 V_53 ,
T_2 V_54 , T_2 V_55 , int V_56 )
{
unsigned int V_57 = V_11 -> V_23 [ V_11 -> V_21 ] . V_58 ;
const char * V_59 = V_56 ? L_17 : L_18 ;
int V_12 ;
F_6 ( & V_11 -> V_2 . V_19 , L_19 ,
V_20 , __LINE__ , V_59 , V_55 , V_54 ) ;
F_27 ( & V_11 -> V_60 ) ;
V_12 = V_56 ? F_28 ( V_11 -> V_2 . V_61 , V_57 ,
V_54 , V_55 , 0 , V_53 ,
& V_11 -> V_62 )
: F_29 ( V_11 -> V_2 . V_61 , V_57 ,
V_54 , V_55 , 0 , V_53 ,
& V_11 -> V_62 ) ;
if ( V_12 ) {
F_6 ( & V_11 -> V_2 . V_19 , L_20 , V_20 ,
__LINE__ , V_59 , V_12 ) ;
return - 1 ;
}
F_30 ( & V_11 -> V_60 ) ;
if ( V_11 -> V_63 ) {
F_6 ( & V_11 -> V_2 . V_19 , L_21 , V_20 ,
__LINE__ , V_59 , V_11 -> V_63 ) ;
return V_11 -> V_63 ;
}
F_6 ( & V_11 -> V_2 . V_19 , L_22 , V_20 , __LINE__ ,
V_59 ) ;
return 0 ;
}
T_2 F_31 ( struct V_10 * V_11 , T_2 V_64 , T_2 V_65 ,
T_2 V_66 , T_2 V_67 , T_2 V_68 )
{
int V_12 ;
F_6 ( & V_11 -> V_2 . V_19 , L_23 , V_20 ,
__LINE__ , V_64 ) ;
F_27 ( & V_11 -> V_60 ) ;
V_12 = F_32 ( V_11 -> V_2 . V_61 , V_64 , V_65 ,
V_66 , V_67 , V_68 , & V_11 -> V_62 ) ;
if ( V_12 ) {
F_13 ( & V_11 -> V_2 . V_19 ,
L_24 ,
V_20 , __LINE__ , V_64 , V_12 ) ;
return - 1 ;
}
F_30 ( & V_11 -> V_60 ) ;
if ( V_11 -> V_63 ) {
F_6 ( & V_11 -> V_2 . V_19 , L_25 ,
V_20 , __LINE__ , V_64 , V_11 -> V_63 ) ;
return V_11 -> V_63 ;
}
F_6 ( & V_11 -> V_2 . V_19 , L_26 , V_20 ,
__LINE__ , V_64 ) ;
return 0 ;
}
