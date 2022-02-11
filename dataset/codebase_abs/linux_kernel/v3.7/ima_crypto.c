static int F_1 ( struct V_1 * V_2 )
{
int V_3 ;
V_2 -> V_4 = F_2 ( V_5 , 0 , V_6 ) ;
if ( F_3 ( V_2 -> V_4 ) ) {
F_4 ( L_1 ,
V_5 , F_5 ( V_2 -> V_4 ) ) ;
V_3 = F_5 ( V_2 -> V_4 ) ;
return V_3 ;
}
V_2 -> V_7 = 0 ;
V_3 = F_6 ( V_2 ) ;
if ( V_3 )
F_7 ( V_2 -> V_4 ) ;
return V_3 ;
}
int F_8 ( struct V_8 * V_8 , char * V_9 )
{
struct V_1 V_2 ;
struct V_10 V_11 [ 1 ] ;
T_1 V_12 , V_13 = 0 ;
char * V_14 ;
int V_3 , V_15 = 0 ;
V_3 = F_1 ( & V_2 ) ;
if ( V_3 != 0 )
return V_3 ;
V_14 = F_9 ( V_16 , V_17 ) ;
if ( ! V_14 ) {
V_3 = - V_18 ;
goto V_19;
}
if ( ! ( V_8 -> V_20 & V_21 ) ) {
V_8 -> V_20 |= V_21 ;
V_15 = 1 ;
}
V_12 = F_10 ( V_8 -> V_22 -> V_23 ) ;
while ( V_13 < V_12 ) {
int V_24 ;
V_24 = F_11 ( V_8 , V_13 , V_14 , V_16 ) ;
if ( V_24 < 0 ) {
V_3 = V_24 ;
break;
}
if ( V_24 == 0 )
break;
V_13 += V_24 ;
F_12 ( V_11 , V_14 , V_24 ) ;
V_3 = F_13 ( & V_2 , V_11 , V_24 ) ;
if ( V_3 )
break;
}
F_14 ( V_14 ) ;
if ( ! V_3 )
V_3 = F_15 ( & V_2 , V_9 ) ;
if ( V_15 )
V_8 -> V_20 &= ~ V_21 ;
V_19:
F_7 ( V_2 . V_4 ) ;
return V_3 ;
}
int F_16 ( int V_25 , void * V_26 , char * V_9 )
{
struct V_1 V_2 ;
struct V_10 V_11 [ 1 ] ;
int V_3 ;
V_3 = F_1 ( & V_2 ) ;
if ( V_3 != 0 )
return V_3 ;
F_12 ( V_11 , V_26 , V_25 ) ;
V_3 = F_13 ( & V_2 , V_11 , V_25 ) ;
if ( ! V_3 )
V_3 = F_15 ( & V_2 , V_9 ) ;
F_7 ( V_2 . V_4 ) ;
return V_3 ;
}
static void T_2 F_17 ( int V_27 , T_3 * V_28 )
{
if ( ! V_29 )
return;
if ( F_18 ( V_30 , V_27 , V_28 ) != 0 )
F_19 ( L_2 ) ;
}
int T_2 F_20 ( char * V_9 )
{
struct V_1 V_2 ;
struct V_10 V_11 ;
T_3 V_31 [ V_32 ] ;
int V_3 , V_33 ;
V_3 = F_1 ( & V_2 ) ;
if ( V_3 != 0 )
return V_3 ;
for ( V_33 = V_34 ; V_33 < V_35 ; V_33 ++ ) {
F_17 ( V_33 , V_31 ) ;
F_12 ( & V_11 , V_31 , V_32 ) ;
V_3 = F_13 ( & V_2 , & V_11 , V_32 ) ;
}
if ( ! V_3 )
F_15 ( & V_2 , V_9 ) ;
F_7 ( V_2 . V_4 ) ;
return V_3 ;
}
