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
F_9 ( V_8 ) -> V_21 [ 0 ] = V_22 ;
F_9 ( V_8 ) -> V_23 = 1 ;
F_10 ( V_8 ) -> type = V_24 ;
V_8 -> V_25 = & V_2 ;
F_11 ( V_5 , NULL , V_8 , 1 ) ;
V_9 = F_9 ( V_8 ) -> V_26 ? - V_27 : 0 ;
F_12 ( V_8 ) ;
if ( V_9 )
goto V_28;
V_8 = F_8 ( V_5 , V_19 , V_29 ) ;
if ( F_13 ( V_8 ) )
goto V_28;
F_9 ( V_8 ) -> V_21 [ 0 ] = V_30 ;
F_9 ( V_8 ) -> V_23 = 1 ;
F_10 ( V_8 ) -> type = V_24 ;
F_14 ( V_5 , V_8 , V_31 ) ;
V_28:
return;
}
T_3 F_15 ( T_1 * V_1 , struct V_7 * V_8 )
{
struct V_32 V_21 ;
struct V_33 * V_34 = & V_21 . V_34 ;
memset ( & V_21 , 0 , sizeof( V_21 ) ) ;
if ( F_9 ( V_8 ) -> V_21 [ 0 ] == V_22 ) {
V_1 -> V_15 = * ( unsigned long * ) V_8 -> V_25 ;
V_1 -> V_12 |= V_35 ;
V_34 -> V_36 = V_37 ;
V_34 -> V_38 = 0x44 ;
V_34 -> V_39 = 0x4c ;
V_34 -> V_40 = 0x4e ;
V_34 -> V_41 = 0x55 ;
V_21 . V_42 . V_28 . V_34 = V_43 | V_44 ;
V_21 . V_42 . V_45 . V_34 = V_46 | V_44 ;
} else
V_34 -> V_36 = V_47 ;
V_21 . V_48 |= V_49 ;
V_21 . V_50 = V_51 ;
V_21 . V_8 = V_8 ;
return F_16 ( V_1 , & V_21 ) ;
}
T_4 F_17 ( struct V_52 * V_53 , struct V_54 * V_55 ,
char * V_56 )
{
T_1 * V_1 = F_18 ( V_53 ) ;
T_2 * V_3 = V_1 -> V_3 ;
unsigned long V_57 ;
unsigned int V_58 ;
if ( V_1 -> V_12 & V_59 )
return - V_60 ;
F_2 ( & V_3 -> V_11 ) ;
V_57 = V_10 ;
if ( V_1 -> V_12 & V_13 &&
F_19 ( V_1 -> V_15 , V_57 ) )
V_58 = F_20 ( V_1 -> V_15 - V_57 ) ;
else
V_58 = 0 ;
F_6 ( & V_3 -> V_11 ) ;
return snprintf ( V_56 , 20 , L_1 , V_58 ) ;
}
T_4 F_21 ( struct V_52 * V_53 , struct V_54 * V_55 ,
const char * V_56 , T_5 V_61 )
{
#define F_22 30000
T_1 * V_1 = F_18 ( V_53 ) ;
long int V_62 ;
int V_9 ;
V_9 = F_23 ( V_56 , 10 , & V_62 ) ;
if ( V_9 )
return V_9 ;
if ( V_62 < - 2 )
return - V_63 ;
if ( V_62 > F_22 ) {
V_62 = F_22 ;
V_9 = - V_64 ;
}
F_24 ( & V_65 ) ;
if ( V_62 >= 0 ) {
if ( V_1 -> V_12 & V_59 )
V_9 = - V_60 ;
else if ( V_62 || V_1 -> V_12 & V_13 )
F_1 ( V_1 , F_25 ( V_62 ) ) ;
} else {
if ( V_1 -> V_66 == V_67 )
switch ( V_62 ) {
case - 1 :
V_1 -> V_12 &= ~ V_59 ;
break;
case - 2 :
V_1 -> V_12 |= V_59 ;
break;
}
else
V_9 = - V_60 ;
}
F_26 ( & V_65 ) ;
return V_9 ? V_9 : V_61 ;
}
