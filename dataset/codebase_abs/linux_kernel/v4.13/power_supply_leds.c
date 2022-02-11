static void F_1 ( struct V_1 * V_2 )
{
union V_3 V_4 ;
unsigned long V_5 = 0 ;
unsigned long V_6 = 0 ;
if ( F_2 ( V_2 , V_7 , & V_4 ) )
return;
F_3 ( & V_2 -> V_8 , L_1 , V_9 , V_4 . V_10 ) ;
switch ( V_4 . V_10 ) {
case V_11 :
F_4 ( V_2 -> V_12 , V_13 ) ;
F_4 ( V_2 -> V_14 , V_15 ) ;
F_4 ( V_2 -> V_16 , V_13 ) ;
F_4 ( V_2 -> V_17 ,
V_13 ) ;
break;
case V_18 :
F_4 ( V_2 -> V_12 , V_13 ) ;
F_4 ( V_2 -> V_14 , V_13 ) ;
F_4 ( V_2 -> V_16 , V_15 ) ;
F_5 ( V_2 -> V_17 ,
& V_5 , & V_6 ) ;
break;
default:
F_4 ( V_2 -> V_12 , V_15 ) ;
F_4 ( V_2 -> V_14 , V_15 ) ;
F_4 ( V_2 -> V_16 , V_15 ) ;
F_4 ( V_2 -> V_17 ,
V_15 ) ;
break;
}
}
static int F_6 ( struct V_1 * V_2 )
{
V_2 -> V_19 = F_7 ( V_20 ,
L_2 , V_2 -> V_21 -> V_22 ) ;
if ( ! V_2 -> V_19 )
goto V_23;
V_2 -> V_24 = F_7 ( V_20 ,
L_3 , V_2 -> V_21 -> V_22 ) ;
if ( ! V_2 -> V_24 )
goto V_25;
V_2 -> V_26 = F_7 ( V_20 , L_4 , V_2 -> V_21 -> V_22 ) ;
if ( ! V_2 -> V_26 )
goto V_27;
V_2 -> V_28 = F_7 ( V_20 ,
L_5 , V_2 -> V_21 -> V_22 ) ;
if ( ! V_2 -> V_28 )
goto V_29;
F_8 ( V_2 -> V_19 ,
& V_2 -> V_12 ) ;
F_8 ( V_2 -> V_24 ,
& V_2 -> V_14 ) ;
F_8 ( V_2 -> V_26 ,
& V_2 -> V_16 ) ;
F_8 ( V_2 -> V_28 ,
& V_2 -> V_17 ) ;
return 0 ;
V_29:
F_9 ( V_2 -> V_26 ) ;
V_27:
F_9 ( V_2 -> V_24 ) ;
V_25:
F_9 ( V_2 -> V_19 ) ;
V_23:
return - V_30 ;
}
static void F_10 ( struct V_1 * V_2 )
{
F_11 ( V_2 -> V_12 ) ;
F_11 ( V_2 -> V_14 ) ;
F_11 ( V_2 -> V_16 ) ;
F_11 ( V_2 -> V_17 ) ;
F_9 ( V_2 -> V_28 ) ;
F_9 ( V_2 -> V_26 ) ;
F_9 ( V_2 -> V_24 ) ;
F_9 ( V_2 -> V_19 ) ;
}
static void F_12 ( struct V_1 * V_2 )
{
union V_3 V_31 ;
if ( F_2 ( V_2 , V_32 , & V_31 ) )
return;
F_3 ( & V_2 -> V_8 , L_1 , V_9 , V_31 . V_10 ) ;
if ( V_31 . V_10 )
F_4 ( V_2 -> V_33 , V_13 ) ;
else
F_4 ( V_2 -> V_33 , V_15 ) ;
}
static int F_13 ( struct V_1 * V_2 )
{
V_2 -> V_34 = F_7 ( V_20 , L_6 ,
V_2 -> V_21 -> V_22 ) ;
if ( ! V_2 -> V_34 )
return - V_30 ;
F_8 ( V_2 -> V_34 , & V_2 -> V_33 ) ;
return 0 ;
}
static void F_14 ( struct V_1 * V_2 )
{
F_11 ( V_2 -> V_33 ) ;
F_9 ( V_2 -> V_34 ) ;
}
void F_15 ( struct V_1 * V_2 )
{
if ( V_2 -> V_21 -> type == V_35 )
F_1 ( V_2 ) ;
else
F_12 ( V_2 ) ;
}
int F_16 ( struct V_1 * V_2 )
{
if ( V_2 -> V_21 -> type == V_35 )
return F_6 ( V_2 ) ;
return F_13 ( V_2 ) ;
}
void F_17 ( struct V_1 * V_2 )
{
if ( V_2 -> V_21 -> type == V_35 )
F_10 ( V_2 ) ;
else
F_14 ( V_2 ) ;
}
