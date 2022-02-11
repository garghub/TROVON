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
F_9 ( V_8 ) ;
F_10 ( V_8 ) -> V_21 [ 0 ] = V_22 ;
F_10 ( V_8 ) -> V_23 = 1 ;
F_11 ( V_8 ) -> type = V_24 ;
V_8 -> V_25 = & V_2 ;
V_9 = F_12 ( V_5 , NULL , V_8 , 1 ) ;
F_13 ( V_8 ) ;
if ( V_9 )
goto V_26;
V_8 = F_8 ( V_5 , V_19 , V_27 ) ;
F_9 ( V_8 ) ;
if ( F_14 ( V_8 ) )
goto V_26;
F_10 ( V_8 ) -> V_21 [ 0 ] = V_28 ;
F_10 ( V_8 ) -> V_23 = 1 ;
F_11 ( V_8 ) -> type = V_24 ;
F_15 ( V_5 , V_8 , V_29 ) ;
V_26:
return;
}
T_3 F_16 ( T_1 * V_1 , struct V_7 * V_8 )
{
struct V_30 V_21 ;
struct V_31 * V_32 = & V_21 . V_32 ;
memset ( & V_21 , 0 , sizeof( V_21 ) ) ;
if ( F_10 ( V_8 ) -> V_21 [ 0 ] == V_22 ) {
V_1 -> V_15 = * ( unsigned long * ) V_8 -> V_25 ;
V_1 -> V_12 |= V_33 ;
V_32 -> V_34 = V_35 ;
V_32 -> V_36 = 0x44 ;
V_32 -> V_37 = 0x4c ;
V_32 -> V_38 = 0x4e ;
V_32 -> V_39 = 0x55 ;
V_21 . V_40 . V_26 . V_32 = V_41 | V_42 ;
V_21 . V_40 . V_43 . V_32 = V_44 | V_42 ;
} else
V_32 -> V_34 = V_45 ;
V_21 . V_46 |= V_47 ;
V_21 . V_48 = V_49 ;
V_21 . V_8 = V_8 ;
return F_17 ( V_1 , & V_21 ) ;
}
T_4 F_18 ( struct V_50 * V_51 , struct V_52 * V_53 ,
char * V_54 )
{
T_1 * V_1 = F_19 ( V_51 ) ;
T_2 * V_3 = V_1 -> V_3 ;
unsigned long V_55 ;
unsigned int V_56 ;
if ( V_1 -> V_12 & V_57 )
return - V_58 ;
F_2 ( & V_3 -> V_11 ) ;
V_55 = V_10 ;
if ( V_1 -> V_12 & V_13 &&
F_20 ( V_1 -> V_15 , V_55 ) )
V_56 = F_21 ( V_1 -> V_15 - V_55 ) ;
else
V_56 = 0 ;
F_6 ( & V_3 -> V_11 ) ;
return snprintf ( V_54 , 20 , L_1 , V_56 ) ;
}
T_4 F_22 ( struct V_50 * V_51 , struct V_52 * V_53 ,
const char * V_54 , T_5 V_59 )
{
#define F_23 30000
T_1 * V_1 = F_19 ( V_51 ) ;
long int V_60 ;
int V_9 ;
V_9 = F_24 ( V_54 , 10 , & V_60 ) ;
if ( V_9 )
return V_9 ;
if ( V_60 < - 2 )
return - V_61 ;
if ( V_60 > F_23 ) {
V_60 = F_23 ;
V_9 = - V_62 ;
}
F_25 ( & V_63 ) ;
if ( V_60 >= 0 ) {
if ( V_1 -> V_12 & V_57 )
V_9 = - V_58 ;
else if ( V_60 || V_1 -> V_12 & V_13 )
F_1 ( V_1 , F_26 ( V_60 ) ) ;
} else {
if ( V_1 -> V_64 == V_65 )
switch ( V_60 ) {
case - 1 :
V_1 -> V_12 &= ~ V_57 ;
break;
case - 2 :
V_1 -> V_12 |= V_57 ;
break;
}
else
V_9 = - V_58 ;
}
F_27 ( & V_63 ) ;
return V_9 ? V_9 : V_59 ;
}
