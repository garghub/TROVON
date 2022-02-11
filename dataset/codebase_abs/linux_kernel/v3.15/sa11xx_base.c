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
return F_3 ( V_2 , F_18 ( 0 ) ) ;
}
static int
F_19 ( struct V_1 * V_2 , char * V_28 )
{
struct V_6 V_7 ;
unsigned int clock = F_18 ( 0 ) ;
unsigned long V_8 = V_19 ;
char * V_29 = V_28 ;
F_4 ( V_2 , & V_7 ) ;
V_29 += sprintf ( V_29 , L_2 , V_7 . V_16 ,
F_20 ( clock , F_15 ( V_8 , V_2 -> V_20 ) ) ) ;
V_29 += sprintf ( V_29 , L_3 , V_7 . V_18 ,
F_20 ( clock , F_14 ( V_8 , V_2 -> V_20 ) ) ) ;
V_29 += sprintf ( V_29 , L_4 , V_7 . V_17 ,
F_20 ( clock , F_13 ( V_8 , V_2 -> V_20 ) ) ) ;
return V_29 - V_28 ;
}
int F_21 ( struct V_1 * V_2 )
{
V_2 -> V_30 . V_31 = F_22 ( V_2 -> V_20 ) ;
V_2 -> V_30 . V_32 = F_22 ( V_2 -> V_20 ) + V_33 - 1 ;
V_2 -> V_30 . V_34 = V_35 [ V_2 -> V_20 ] ;
V_2 -> V_30 . V_10 = V_36 ;
V_2 -> V_37 . V_31 = F_23 ( V_2 -> V_20 ) ;
V_2 -> V_37 . V_32 = F_23 ( V_2 -> V_20 ) + V_38 - 1 ;
V_2 -> V_37 . V_34 = L_5 ;
V_2 -> V_37 . V_10 = V_36 | V_39 ;
V_2 -> V_40 . V_31 = F_24 ( V_2 -> V_20 ) ;
V_2 -> V_40 . V_32 = F_24 ( V_2 -> V_20 ) + V_41 - 1 ;
V_2 -> V_40 . V_34 = L_6 ;
V_2 -> V_40 . V_10 = V_36 ;
V_2 -> V_42 . V_31 = F_25 ( V_2 -> V_20 ) ;
V_2 -> V_42 . V_32 = F_25 ( V_2 -> V_20 ) + V_43 - 1 ;
V_2 -> V_42 . V_34 = L_7 ;
V_2 -> V_42 . V_10 = V_36 ;
return F_26 ( V_2 ) ;
}
void F_27 ( struct V_44 * V_14 )
{
if ( ! V_14 -> V_15 )
V_14 -> V_15 = F_1 ;
V_14 -> V_45 = F_17 ;
V_14 -> V_46 = F_19 ;
#ifdef F_28
V_14 -> V_47 = F_16 ;
#endif
}
int F_29 ( struct V_48 * V_49 , struct V_44 * V_14 ,
int V_50 , int V_20 )
{
struct V_51 * V_52 ;
struct V_1 * V_2 ;
int V_53 , V_54 = 0 ;
F_27 ( V_14 ) ;
V_52 = F_30 ( F_31 ( V_20 ) , V_55 ) ;
if ( ! V_52 )
return - V_56 ;
V_52 -> V_57 = V_20 ;
for ( V_53 = 0 ; V_53 < V_20 ; V_53 ++ ) {
V_2 = & V_52 -> V_2 [ V_53 ] ;
V_2 -> V_20 = V_50 + V_53 ;
F_32 ( V_2 , V_14 , V_49 ) ;
V_54 = F_21 ( V_2 ) ;
if ( V_54 )
break;
}
if ( V_54 ) {
while ( -- V_53 >= 0 )
F_33 ( & V_52 -> V_2 [ V_53 ] ) ;
F_34 ( V_52 ) ;
} else {
F_35 ( V_49 , V_52 ) ;
}
return V_54 ;
}
static int T_2 F_36 ( void )
{
return 0 ;
}
static void T_3 F_37 ( void ) {}
