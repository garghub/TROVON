static
T_1 F_1 ( struct V_1 * V_1 , void * V_2 , T_2 V_3 )
{
int V_4 ;
struct V_5 * V_6 = & V_1 -> V_7 -> V_6 ;
int V_8 ;
struct V_9 * V_10 ;
int V_11 , V_12 = 1 ;
V_4 = F_2 ( V_1 -> V_7 ) ;
if ( V_4 < 0 ) {
F_3 ( V_6 , L_1 , V_4 ) ;
V_12 = 0 ;
}
V_10 = F_4 ( V_1 -> V_7 , V_1 -> V_13 . V_14 ) ;
V_11 = F_5 ( V_1 -> V_15 , V_10 -> V_16 ) ;
V_17:
V_4 = F_6 ( V_1 -> V_15 , V_11 , V_2 , V_3 , & V_8 , 200 ) ;
switch ( V_4 ) {
case 0 :
if ( V_8 != V_3 ) {
F_3 ( V_6 , L_2
L_3 , V_8 , V_3 ) ;
V_4 = - V_18 ;
break;
}
V_4 = V_8 ;
break;
case - V_19 :
if ( F_7 ( & V_1 -> V_20 ,
10 * V_21 , V_22 ) ) {
F_3 ( V_6 , L_4
L_5 ) ;
F_8 ( V_1 -> V_7 ) ;
} else {
F_9 ( V_1 -> V_15 , V_11 ) ;
F_10 ( 10 ) ;
goto V_17;
}
case - V_23 :
case - V_24 :
case - V_25 :
case - V_26 :
case - V_27 :
V_4 = - V_26 ;
break;
case - V_28 :
break;
default:
if ( F_7 ( & V_1 -> V_20 ,
V_21 , V_22 ) ) {
F_3 ( V_6 , L_6
L_7 ) ;
F_8 ( V_1 -> V_7 ) ;
V_4 = - V_24 ;
break;
}
F_3 ( V_6 , L_8 ,
V_4 ) ;
goto V_17;
}
if ( V_12 )
F_11 ( V_1 -> V_7 ) ;
return V_4 ;
}
T_1 F_12 ( struct V_29 * V_29 ,
const struct V_30 * V_31 ,
T_2 V_32 , int V_33 )
{
T_1 V_4 ;
struct V_5 * V_6 = F_13 ( V_29 ) ;
struct V_1 * V_1 = F_14 ( V_29 , struct V_1 , V_29 ) ;
int V_34 = V_31 == NULL ? - 1 : F_15 ( V_31 ) ;
struct V_30 * V_35 ;
T_2 V_36 = F_16 ( V_32 , 16 ) ;
F_17 ( 8 , V_6 , L_9 ,
V_29 , V_31 , V_32 ) ;
V_4 = - V_37 ;
if ( V_32 > V_38 )
goto V_39;
if ( V_31 != V_29 -> V_40 )
memmove ( V_29 -> V_40 , V_31 , V_32 ) ;
V_35 = V_29 -> V_40 ;
if ( V_36 > V_32 )
memset ( V_29 -> V_40 + V_32 , 0 , V_36 - V_32 ) ;
if ( ( V_33 & V_41 ) == 0 ) {
if ( F_18 ( F_19 ( V_35 ) == 0 ) )
F_20 ( V_6 , L_10 ) ;
F_21 ( V_35 ) ;
}
V_4 = F_1 ( V_1 , V_29 -> V_40 , V_32 ) ;
if ( V_4 < 0 ) {
F_3 ( V_6 , L_11 ,
V_34 , V_4 ) ;
goto V_42;
}
if ( V_4 != V_32 ) {
F_3 ( V_6 , L_12
L_13 , V_34 , V_4 , V_32 ) ;
V_4 = - V_18 ;
goto V_43;
}
V_43:
V_42:
V_39:
F_22 ( 8 , V_6 , L_14 ,
V_29 , V_31 , V_32 , V_4 ) ;
return V_4 ;
}
static
void F_23 ( struct V_44 * V_44 )
{
F_24 ( V_44 -> V_45 ) ;
}
static
int F_25 ( struct V_1 * V_1 , struct V_44 * V_44 ,
struct V_46 * V_46 )
{
struct V_29 * V_29 = & V_1 -> V_29 ;
struct V_9 * V_10 ;
int V_11 ;
V_10 = F_4 ( V_1 -> V_7 ,
V_1 -> V_13 . V_47 ) ;
V_11 = F_26 ( V_1 -> V_15 , V_10 -> V_16 ) ;
F_27 ( V_44 , V_1 -> V_15 , V_11 ,
V_29 -> V_48 , V_49 ,
F_23 , V_46 ,
V_10 -> V_50 ) ;
return F_28 ( V_44 , V_51 ) ;
}
T_1 F_29 ( struct V_29 * V_29 ,
struct V_30 * V_52 ,
T_2 V_53 )
{
T_1 V_4 = - V_54 ;
struct V_5 * V_6 = F_13 ( V_29 ) ;
struct V_1 * V_1 = F_14 ( V_29 , struct V_1 , V_29 ) ;
struct V_44 V_55 ;
void * V_56 = V_52 ;
T_2 V_57 , V_8 ;
long V_58 ;
int V_12 = 1 ;
F_30 ( V_59 ) ;
F_17 ( 8 , V_6 , L_15 ,
V_29 , V_56 , V_53 ) ;
F_31 ( V_52 == V_29 -> V_48 ) ;
V_4 = F_2 ( V_1 -> V_7 ) ;
if ( V_4 < 0 ) {
F_3 ( V_6 , L_16 , ( int ) V_4 ) ;
V_12 = 0 ;
}
F_32 ( & V_55 ) ;
F_33 ( & V_55 ) ;
V_57 = 0 ;
while ( V_57 < V_53 ) {
F_34 ( & V_59 ) ;
V_4 = F_25 ( V_1 , & V_55 ,
& V_59 ) ;
if ( V_4 < 0 )
goto V_60;
V_58 = F_35 (
& V_59 , V_61 ) ;
if ( V_58 == 0 ) {
V_4 = - V_28 ;
F_36 ( & V_55 ) ;
goto V_62;
}
if ( V_58 == - V_63 ) {
V_4 = - V_64 ;
F_36 ( & V_55 ) ;
goto V_62;
}
V_4 = V_55 . V_65 ;
switch ( V_4 ) {
case 0 :
break;
case - V_23 :
case - V_24 :
case - V_25 :
case - V_26 :
case - V_27 :
V_4 = - V_26 ;
goto V_66;
default:
F_36 ( & V_55 ) ;
if ( F_7 ( & V_1 -> V_20 ,
V_21 , V_22 ) )
goto V_67;
F_3 ( V_6 , L_17
L_18 , V_55 . V_65 ) ;
continue;
}
if ( V_55 . V_68 == 0 ) {
F_37 ( 6 , V_6 , L_19 ) ;
continue;
}
V_8 = F_38 ( V_53 - V_57 , ( T_2 ) V_55 . V_68 ) ;
memcpy ( V_56 + V_57 , V_29 -> V_48 , V_8 ) ;
V_57 += V_8 ;
}
V_4 = V_57 ;
V_60:
V_62:
V_66:
V_69:
if ( V_12 )
F_11 ( V_1 -> V_7 ) ;
F_22 ( 8 , V_6 , L_20 ,
V_29 , V_56 , V_53 , ( long ) V_4 ) ;
return V_4 ;
V_67:
F_3 ( V_6 , L_21
L_22 ) ;
F_8 ( V_1 -> V_7 ) ;
goto V_69;
}
