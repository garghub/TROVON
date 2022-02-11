static int F_1 ( struct V_1 * V_2 )
{
int V_3 ;
V_3 = F_2 ( V_2 , V_4 ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 = F_2 ( V_2 , V_5 ) ;
if ( V_3 < 0 )
return V_3 ;
return 0 ;
}
static int F_3 ( struct V_1 * V_2 )
{
if ( V_2 -> V_6 == V_7 )
return F_4 ( V_2 , V_8 , V_9 ) ;
else
return F_4 ( V_2 , V_8 , 0 ) ;
}
static int F_5 ( struct V_1 * V_2 )
{
return F_4 ( V_2 , V_10 , 0 ) ;
}
static int F_6 ( struct V_1 * V_2 )
{
int V_3 = F_2 ( V_2 , V_11 ) ;
if ( V_3 < 0 )
return V_3 ;
return 0 ;
}
static int F_7 ( struct V_1 * V_2 )
{
if ( V_2 -> V_6 == V_7 )
return F_4 ( V_2 , V_12 , V_13 ) ;
else
return F_4 ( V_2 , V_12 , 0 ) ;
}
static int F_8 ( struct V_1 * V_2 )
{
int V_14 ;
int V_15 ;
int V_16 = 8 ;
V_14 = F_2 ( V_2 , V_4 ) ;
if ( V_14 < 0 )
return V_14 ;
V_15 = F_2 ( V_2 , V_17 ) ;
if ( V_15 < 0 )
return V_15 ;
do {
V_14 = F_2 ( V_2 , V_4 ) ;
} while ( V_14 >= 0 && V_16 -- && V_14 == V_15 );
if ( V_14 < 0 )
return V_14 ;
if ( ( V_14 & V_18 ) == 0 )
V_2 -> V_19 = 0 ;
else
V_2 -> V_19 = 1 ;
return 0 ;
}
static int F_9 ( struct V_1 * V_2 )
{
int V_20 ;
int V_3 ;
int V_21 ;
V_3 = F_8 ( V_2 ) ;
if ( V_3 )
return V_3 ;
if ( V_22 == V_2 -> V_23 ) {
int V_16 = 1 ;
V_20 = F_2 ( V_2 , V_24 ) ;
if ( V_20 < 0 )
return V_20 ;
do {
V_21 = F_2 ( V_2 , V_25 ) ;
if ( V_21 < 0 )
return V_21 ;
} while ( V_21 == V_20 && V_16 -- );
V_2 -> V_26 = F_10 ( V_21 ) ;
V_21 &= V_20 ;
V_2 -> V_27 = V_28 ;
V_2 -> V_29 = V_30 ;
V_2 -> V_31 = V_2 -> V_32 = 0 ;
if ( V_21 & ( V_33 | V_34 ) ) {
V_2 -> V_27 = V_35 ;
if ( V_21 & V_33 )
V_2 -> V_29 = V_36 ;
} else {
if ( V_21 & V_37 )
V_2 -> V_29 = V_36 ;
}
if ( V_2 -> V_29 == V_36 ) {
V_2 -> V_31 = V_21 & V_38 ? 1 : 0 ;
V_2 -> V_32 = V_21 & V_39 ? 1 : 0 ;
}
} else {
int V_40 = F_2 ( V_2 , V_17 ) ;
if ( V_40 < 0 )
return V_40 ;
if ( V_40 & V_41 )
V_2 -> V_29 = V_36 ;
else
V_2 -> V_29 = V_30 ;
if ( V_40 & V_42 )
V_2 -> V_27 = V_43 ;
else if ( V_40 & V_44 )
V_2 -> V_27 = V_35 ;
else
V_2 -> V_27 = V_28 ;
V_2 -> V_31 = V_2 -> V_32 = 0 ;
V_2 -> V_26 = 0 ;
}
return 0 ;
}
static int F_11 ( struct V_1 * V_2 )
{
int V_45 = F_2 ( V_2 , V_46 ) ;
if ( V_45 & V_47 ) {
V_45 = F_2 ( V_2 , V_17 ) ;
V_45 |= ( V_44 | V_41 ) ;
V_45 &= ~ V_48 ;
F_4 ( V_2 , V_17 , V_45 ) ;
V_2 -> V_49 = F_11 ;
} else {
V_2 -> V_49 = NULL ;
}
return 0 ;
}
static int F_12 ( struct V_1 * V_2 )
{
return V_2 -> V_49 ? 0 : F_13 ( V_2 ) ;
}
