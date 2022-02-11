static void F_1 ( struct V_1 * V_2 )
{
union V_3 V_4 ;
unsigned long V_5 = 0 ;
unsigned long V_6 = 0 ;
if ( V_2 -> V_7 ( V_2 , V_8 , & V_4 ) )
return;
F_2 ( V_2 -> V_9 , L_1 , V_10 , V_4 . V_11 ) ;
switch ( V_4 . V_11 ) {
case V_12 :
F_3 ( V_2 -> V_13 , V_14 ) ;
F_3 ( V_2 -> V_15 , V_16 ) ;
F_3 ( V_2 -> V_17 , V_14 ) ;
F_3 ( V_2 -> V_18 ,
V_14 ) ;
break;
case V_19 :
F_3 ( V_2 -> V_13 , V_14 ) ;
F_3 ( V_2 -> V_15 , V_14 ) ;
F_3 ( V_2 -> V_17 , V_16 ) ;
F_4 ( V_2 -> V_18 ,
& V_5 , & V_6 ) ;
break;
default:
F_3 ( V_2 -> V_13 , V_16 ) ;
F_3 ( V_2 -> V_15 , V_16 ) ;
F_3 ( V_2 -> V_17 , V_16 ) ;
F_3 ( V_2 -> V_18 ,
V_16 ) ;
break;
}
}
static int F_5 ( struct V_1 * V_2 )
{
int V_20 = 0 ;
V_2 -> V_21 = F_6 ( V_22 ,
L_2 , V_2 -> V_23 ) ;
if ( ! V_2 -> V_21 )
goto V_24;
V_2 -> V_25 = F_6 ( V_22 ,
L_3 , V_2 -> V_23 ) ;
if ( ! V_2 -> V_25 )
goto V_26;
V_2 -> V_27 = F_6 ( V_22 , L_4 , V_2 -> V_23 ) ;
if ( ! V_2 -> V_27 )
goto V_28;
V_2 -> V_29 = F_6 ( V_22 ,
L_5 , V_2 -> V_23 ) ;
if ( ! V_2 -> V_29 )
goto V_30;
F_7 ( V_2 -> V_21 ,
& V_2 -> V_13 ) ;
F_7 ( V_2 -> V_25 ,
& V_2 -> V_15 ) ;
F_7 ( V_2 -> V_27 ,
& V_2 -> V_17 ) ;
F_7 ( V_2 -> V_29 ,
& V_2 -> V_18 ) ;
goto V_31;
V_30:
F_8 ( V_2 -> V_27 ) ;
V_28:
F_8 ( V_2 -> V_25 ) ;
V_26:
F_8 ( V_2 -> V_21 ) ;
V_24:
V_20 = - V_32 ;
V_31:
return V_20 ;
}
static void F_9 ( struct V_1 * V_2 )
{
F_10 ( V_2 -> V_13 ) ;
F_10 ( V_2 -> V_15 ) ;
F_10 ( V_2 -> V_17 ) ;
F_10 ( V_2 -> V_18 ) ;
F_8 ( V_2 -> V_29 ) ;
F_8 ( V_2 -> V_27 ) ;
F_8 ( V_2 -> V_25 ) ;
F_8 ( V_2 -> V_21 ) ;
}
static void F_11 ( struct V_1 * V_2 )
{
union V_3 V_33 ;
if ( V_2 -> V_7 ( V_2 , V_34 , & V_33 ) )
return;
F_2 ( V_2 -> V_9 , L_1 , V_10 , V_33 . V_11 ) ;
if ( V_33 . V_11 )
F_3 ( V_2 -> V_35 , V_14 ) ;
else
F_3 ( V_2 -> V_35 , V_16 ) ;
}
static int F_12 ( struct V_1 * V_2 )
{
int V_20 = 0 ;
V_2 -> V_36 = F_6 ( V_22 , L_6 , V_2 -> V_23 ) ;
if ( ! V_2 -> V_36 )
goto V_37;
F_7 ( V_2 -> V_36 , & V_2 -> V_35 ) ;
goto V_31;
V_37:
V_20 = - V_32 ;
V_31:
return V_20 ;
}
static void F_13 ( struct V_1 * V_2 )
{
F_10 ( V_2 -> V_35 ) ;
F_8 ( V_2 -> V_36 ) ;
}
void F_14 ( struct V_1 * V_2 )
{
if ( V_2 -> type == V_38 )
F_1 ( V_2 ) ;
else
F_11 ( V_2 ) ;
}
int F_15 ( struct V_1 * V_2 )
{
if ( V_2 -> type == V_38 )
return F_5 ( V_2 ) ;
return F_12 ( V_2 ) ;
}
void F_16 ( struct V_1 * V_2 )
{
if ( V_2 -> type == V_38 )
F_9 ( V_2 ) ;
else
F_13 ( V_2 ) ;
}
