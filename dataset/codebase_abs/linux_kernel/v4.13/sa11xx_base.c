static unsigned int
F_1 ( struct V_1 * V_2 ,
unsigned int V_3 ,
unsigned int V_4 )
{
return F_2 ( V_4 , V_3 ) ;
}
static int
F_3 ( struct V_1 * V_2 , unsigned int V_5 )
{
struct V_6 V_7 ;
T_1 V_8 , V_9 ;
unsigned long V_10 ;
unsigned int V_11 , V_12 , V_13 ;
F_4 ( V_2 , & V_7 ) ;
V_11 = V_2 -> V_14 -> V_15 ( V_2 , V_5 , V_7 . V_16 ) ;
V_12 = V_2 -> V_14 -> V_15 ( V_2 , V_5 , V_7 . V_17 ) ;
V_13 = V_2 -> V_14 -> V_15 ( V_2 , V_5 , V_7 . V_18 ) ;
F_5 ( V_10 ) ;
V_9 = V_8 = V_19 ;
F_6 ( V_8 , V_2 -> V_20 , 0 ) ;
F_7 ( V_8 , V_2 -> V_20 , V_11 ) ;
F_8 ( V_8 , V_2 -> V_20 , V_13 ) ;
F_9 ( V_8 , V_2 -> V_20 , V_12 ) ;
if ( V_9 != V_8 )
V_19 = V_8 ;
F_10 ( V_10 ) ;
F_11 ( V_2 , 2 , L_1 ,
F_12 ( V_8 , V_2 -> V_20 ) ,
F_13 ( V_8 , V_2 -> V_20 ) , F_14 ( V_8 , V_2 -> V_20 ) ,
F_15 ( V_8 , V_2 -> V_20 ) ) ;
return 0 ;
}
static int
F_16 ( struct V_1 * V_2 ,
unsigned long V_21 ,
struct V_22 * V_23 )
{
switch ( V_21 ) {
case V_24 :
if ( V_23 -> V_25 > V_23 -> V_26 )
F_3 ( V_2 , V_23 -> V_25 ) ;
break;
case V_27 :
if ( V_23 -> V_25 < V_23 -> V_26 )
F_3 ( V_2 , V_23 -> V_25 ) ;
break;
}
return 0 ;
}
static int
F_17 ( struct V_1 * V_2 )
{
unsigned long V_28 = F_18 ( V_2 -> V_28 ) ;
return F_3 ( V_2 , V_28 / 1000 ) ;
}
static int
F_19 ( struct V_1 * V_2 , char * V_29 )
{
struct V_6 V_7 ;
unsigned int clock = F_18 ( V_2 -> V_28 ) / 1000 ;
unsigned long V_8 = V_19 ;
char * V_30 = V_29 ;
F_4 ( V_2 , & V_7 ) ;
V_30 += sprintf ( V_30 , L_2 , V_7 . V_16 ,
F_20 ( clock , F_15 ( V_8 , V_2 -> V_20 ) ) ) ;
V_30 += sprintf ( V_30 , L_3 , V_7 . V_18 ,
F_20 ( clock , F_14 ( V_8 , V_2 -> V_20 ) ) ) ;
V_30 += sprintf ( V_30 , L_4 , V_7 . V_17 ,
F_20 ( clock , F_13 ( V_8 , V_2 -> V_20 ) ) ) ;
return V_30 - V_29 ;
}
int F_21 ( struct V_1 * V_2 )
{
V_2 -> V_31 . V_32 = F_22 ( V_2 -> V_20 ) ;
V_2 -> V_31 . V_33 = F_22 ( V_2 -> V_20 ) + V_34 - 1 ;
V_2 -> V_31 . V_35 = V_36 [ V_2 -> V_20 ] ;
V_2 -> V_31 . V_10 = V_37 ;
V_2 -> V_38 . V_32 = F_23 ( V_2 -> V_20 ) ;
V_2 -> V_38 . V_33 = F_23 ( V_2 -> V_20 ) + V_39 - 1 ;
V_2 -> V_38 . V_35 = L_5 ;
V_2 -> V_38 . V_10 = V_37 | V_40 ;
V_2 -> V_41 . V_32 = F_24 ( V_2 -> V_20 ) ;
V_2 -> V_41 . V_33 = F_24 ( V_2 -> V_20 ) + V_42 - 1 ;
V_2 -> V_41 . V_35 = L_6 ;
V_2 -> V_41 . V_10 = V_37 ;
V_2 -> V_43 . V_32 = F_25 ( V_2 -> V_20 ) ;
V_2 -> V_43 . V_33 = F_25 ( V_2 -> V_20 ) + V_44 - 1 ;
V_2 -> V_43 . V_35 = L_7 ;
V_2 -> V_43 . V_10 = V_37 ;
return F_26 ( V_2 ) ;
}
void F_27 ( struct V_45 * V_14 )
{
if ( ! V_14 -> V_15 )
V_14 -> V_15 = F_1 ;
V_14 -> V_46 = F_17 ;
V_14 -> V_47 = F_19 ;
#ifdef F_28
V_14 -> V_48 = F_16 ;
#endif
}
int F_29 ( struct V_49 * V_50 , struct V_45 * V_14 ,
int V_51 , int V_20 )
{
struct V_52 * V_53 ;
struct V_1 * V_2 ;
int V_54 , V_55 = 0 ;
struct V_28 * V_28 ;
V_28 = F_30 ( V_50 , NULL ) ;
if ( F_31 ( V_28 ) )
return F_32 ( V_28 ) ;
F_27 ( V_14 ) ;
V_53 = F_33 ( V_50 , F_34 ( V_20 ) , V_56 ) ;
if ( ! V_53 )
return - V_57 ;
V_53 -> V_58 = V_20 ;
for ( V_54 = 0 ; V_54 < V_20 ; V_54 ++ ) {
V_2 = & V_53 -> V_2 [ V_54 ] ;
V_2 -> V_20 = V_51 + V_54 ;
V_2 -> V_28 = V_28 ;
F_35 ( V_2 , V_14 , V_50 ) ;
V_55 = F_21 ( V_2 ) ;
if ( V_55 )
break;
}
if ( V_55 ) {
while ( -- V_54 >= 0 )
F_36 ( & V_53 -> V_2 [ V_54 ] ) ;
} else {
F_37 ( V_50 , V_53 ) ;
}
return V_55 ;
}
