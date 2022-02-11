static void F_1 ( T_1 * V_1 , unsigned long V_2 )
{
T_2 * V_3 = V_1 -> V_3 ;
struct V_4 * V_5 = V_1 -> V_6 ;
struct V_7 * V_8 ;
int V_9 ;
V_2 += V_10 ;
F_2 ( & V_3 -> V_11 ) ;
if ( V_1 -> V_12 & V_13 ) {
int V_14 = F_3 ( V_2 , V_1 -> V_15 ) ;
int V_16 = 0 ;
V_1 -> V_15 = V_2 ;
F_4 ( & V_17 ) ;
if ( V_14 && F_5 ( & V_3 -> V_18 ) )
V_16 = 1 ;
F_6 ( & V_3 -> V_11 ) ;
if ( V_16 )
F_7 ( V_5 ) ;
return;
}
F_6 ( & V_3 -> V_11 ) ;
V_8 = F_8 ( V_5 , V_19 , V_20 ) ;
V_8 -> V_21 [ 0 ] = V_22 ;
V_8 -> V_23 = 1 ;
V_8 -> V_24 = V_25 ;
V_8 -> V_26 = & V_2 ;
V_9 = F_9 ( V_5 , NULL , V_8 , 1 ) ;
F_10 ( V_8 ) ;
if ( V_9 )
goto V_27;
V_8 = F_8 ( V_5 , V_19 , V_28 ) ;
if ( F_11 ( ! V_8 ) )
goto V_27;
V_8 -> V_21 [ 0 ] = V_29 ;
V_8 -> V_23 = 1 ;
V_8 -> V_24 = V_25 ;
F_12 ( V_5 , V_8 , V_30 ) ;
V_27:
return;
}
T_3 F_13 ( T_1 * V_1 , struct V_7 * V_8 )
{
struct V_31 V_21 ;
struct V_32 * V_33 = & V_21 . V_33 ;
memset ( & V_21 , 0 , sizeof( V_21 ) ) ;
if ( V_8 -> V_21 [ 0 ] == V_22 ) {
V_1 -> V_15 = * ( unsigned long * ) V_8 -> V_26 ;
V_1 -> V_12 |= V_34 ;
V_33 -> V_35 = V_36 ;
V_33 -> V_37 = 0x44 ;
V_33 -> V_38 = 0x4c ;
V_33 -> V_39 = 0x4e ;
V_33 -> V_40 = 0x55 ;
V_21 . V_41 . V_27 . V_33 = V_42 | V_43 ;
V_21 . V_41 . V_44 . V_33 = V_45 | V_43 ;
} else
V_33 -> V_35 = V_46 ;
V_21 . V_47 |= V_48 ;
V_21 . V_49 = V_50 ;
V_21 . V_8 = V_8 ;
return F_14 ( V_1 , & V_21 ) ;
}
T_4 F_15 ( struct V_51 * V_52 , struct V_53 * V_54 ,
char * V_55 )
{
T_1 * V_1 = F_16 ( V_52 ) ;
T_2 * V_3 = V_1 -> V_3 ;
unsigned long V_56 ;
unsigned int V_57 ;
if ( V_1 -> V_12 & V_58 )
return - V_59 ;
F_2 ( & V_3 -> V_11 ) ;
V_56 = V_10 ;
if ( V_1 -> V_12 & V_13 &&
F_17 ( V_1 -> V_15 , V_56 ) )
V_57 = F_18 ( V_1 -> V_15 - V_56 ) ;
else
V_57 = 0 ;
F_6 ( & V_3 -> V_11 ) ;
return snprintf ( V_55 , 20 , L_1 , V_57 ) ;
}
T_4 F_19 ( struct V_51 * V_52 , struct V_53 * V_54 ,
const char * V_55 , T_5 V_60 )
{
#define F_20 30000
T_1 * V_1 = F_16 ( V_52 ) ;
long int V_61 ;
int V_9 ;
V_9 = F_21 ( V_55 , 10 , & V_61 ) ;
if ( V_9 )
return V_9 ;
if ( V_61 < - 2 )
return - V_62 ;
if ( V_61 > F_20 ) {
V_61 = F_20 ;
V_9 = - V_63 ;
}
F_22 ( & V_64 ) ;
if ( V_61 >= 0 ) {
if ( V_1 -> V_12 & V_58 )
V_9 = - V_59 ;
else if ( V_61 || V_1 -> V_12 & V_13 )
F_1 ( V_1 , F_23 ( V_61 ) ) ;
} else {
if ( V_1 -> V_65 == V_66 )
switch ( V_61 ) {
case - 1 :
V_1 -> V_12 &= ~ V_58 ;
break;
case - 2 :
V_1 -> V_12 |= V_58 ;
break;
}
else
V_9 = - V_59 ;
}
F_24 ( & V_64 ) ;
return V_9 ? V_9 : V_60 ;
}
