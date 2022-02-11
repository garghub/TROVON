static int T_1 F_1 ( char * V_1 )
{
V_2 = 1 ;
return 1 ;
}
int F_2 ( struct V_3 * V_4 )
{
struct V_5 * V_6 ;
unsigned long V_7 = 0 , V_8 = 0 ;
struct V_9 * V_10 [ V_11 ] ;
int V_12 , V_13 ;
if ( F_3 ( V_2 ) )
return 0 ;
if ( ( unsigned long ) V_4 & ( V_14 - 1 ) )
goto V_15;
for ( V_12 = 0 ; V_12 < V_4 -> V_16 ; V_12 ++ ) {
V_6 = V_4 -> V_5 + V_12 ;
V_7 += F_4 ( F_5 ( V_6 ) , V_14 ) ;
V_8 |= V_6 -> V_8 ;
}
if ( F_6 ( V_8 ) != 1 )
goto V_15;
V_13 = V_7 >> V_17 ;
if ( V_13 >= V_11 )
goto V_15;
for ( V_12 = 0 ; V_12 < V_13 ; V_12 ++ )
V_10 [ V_12 ] = F_7 ( V_4 ) ;
V_4 -> V_18 = F_8 ( V_10 , V_13 , V_19 , V_20 ) ;
if ( ! V_4 -> V_18 )
goto V_15;
V_7 = 0 ;
for ( V_12 = 0 ; V_12 < V_4 -> V_16 ; V_12 ++ ) {
V_6 = V_4 -> V_5 + V_12 ;
F_9 ( L_1 ,
( unsigned long ) ( V_4 -> V_18 + V_7 ) ,
V_6 -> V_8 & V_21 ? L_2 : L_3 ,
( unsigned long ) V_6 -> V_22 ) ;
V_7 += F_4 ( F_5 ( V_6 ) , V_14 ) ;
}
V_4 -> V_23 = V_24 ;
F_10 ( & V_4 -> V_25 ) ;
F_11 ( & V_26 ) ;
#ifdef F_12
if ( V_8 & V_21 )
F_13 ( & V_4 -> V_25 , & V_3 ) ;
#endif
#ifdef F_14
if ( V_8 & V_27 )
F_13 ( & V_4 -> V_25 , & V_28 ) ;
#endif
F_15 ( & V_26 ) ;
return 0 ;
V_15:
F_16 ( L_4 ) ;
return - 1 ;
}
void T_2 * F_17 ( struct V_29 * V_25 ,
unsigned long V_30 ,
unsigned long V_31 )
{
unsigned long V_32 ;
struct V_3 * V_4 ;
struct V_5 * V_6 ;
int V_12 , V_7 ;
unsigned long V_8 ;
F_18 ( & V_26 , V_8 ) ;
F_19 (tiop, list, list) {
V_32 = 0 ;
for ( V_12 = 0 ; V_12 < V_4 -> V_16 ; V_12 ++ ) {
V_6 = V_4 -> V_5 + V_12 ;
if ( V_6 -> V_22 == V_30 ) {
F_20 ( & V_26 , V_8 ) ;
return V_4 -> V_18 + V_32 ;
}
V_7 = F_5 ( V_6 ) ;
V_32 += F_4 ( V_7 , V_14 ) ;
}
}
F_20 ( & V_26 , V_8 ) ;
return NULL ;
}
static struct V_3 * F_21 ( unsigned long V_33 )
{
T_3 * V_34 ;
T_4 * V_35 ;
T_5 * V_36 ;
T_6 * V_37 ;
T_6 V_38 ;
V_34 = V_39 + F_22 ( V_33 ) ;
if ( ! F_23 ( * V_34 ) )
return NULL ;
V_35 = F_24 ( V_34 , V_33 ) ;
if ( ! F_25 ( * V_35 ) )
return NULL ;
V_36 = F_26 ( V_35 , V_33 ) ;
if ( ! F_27 ( * V_36 ) )
return NULL ;
V_37 = F_28 ( V_36 , V_33 ) ;
V_38 = * V_37 ;
return F_29 ( F_30 ( V_38 ) ) ;
}
static unsigned long F_31 ( struct V_3 * V_4 ,
unsigned long V_33 )
{
struct V_5 * V_6 ;
unsigned long V_40 = ( unsigned long ) V_4 -> V_18 ;
unsigned long V_7 ;
int V_12 ;
for ( V_12 = 0 ; V_12 < V_4 -> V_16 ; V_12 ++ ) {
V_6 = V_4 -> V_5 + V_12 ;
V_7 = F_4 ( F_5 ( V_6 ) , V_14 ) ;
if ( V_33 < ( V_40 + V_7 ) )
return V_6 -> V_22 + ( V_33 - V_40 ) ;
V_40 += V_7 ;
}
return 0 ;
}
static unsigned long long F_32 ( unsigned long V_41 , int V_42 ,
unsigned long V_43 , int V_44 )
{
unsigned long long V_45 = 0 ;
switch ( V_42 ) {
case 1 :
V_45 = F_33 ( V_41 ) ;
break;
case 2 :
V_45 = F_34 ( V_41 ) ;
break;
case 4 :
V_45 = F_35 ( V_41 ) ;
break;
case 8 :
V_45 = F_36 ( V_41 ) ;
break;
}
switch ( V_44 ) {
case 1 :
F_37 ( V_45 , V_43 ) ;
break;
case 2 :
F_38 ( V_45 , V_43 ) ;
break;
case 4 :
F_39 ( V_45 , V_43 ) ;
break;
case 8 :
F_40 ( V_45 , V_43 ) ;
break;
}
return V_45 ;
}
static unsigned long F_41 ( void * V_46 , const void * V_47 , unsigned long V_48 )
{
struct V_3 * V_4 ;
unsigned long V_41 = ( unsigned long ) V_47 ;
unsigned long long V_45 ;
F_42 ( L_5 , V_41 , V_48 ) ;
V_4 = F_21 ( V_41 ) ;
F_43 ( ! V_4 || ( V_4 -> V_23 != V_24 ) ) ;
V_41 = F_31 ( V_4 , V_41 ) ;
if ( ! V_41 )
return V_48 ;
V_45 = F_32 ( V_41 ,
F_44 (unsigned long, cnt,
(tiop->minimum_bus_width / 8)) ,
( unsigned long ) V_46 , V_48 ) ;
F_42 ( L_6 , V_41 , V_45 ) ;
return 0 ;
}
static unsigned long F_45 ( void * V_46 , const void * V_47 , unsigned long V_48 )
{
struct V_3 * V_4 ;
unsigned long V_43 = ( unsigned long ) V_46 ;
unsigned long long V_45 ;
F_42 ( L_7 , V_43 , V_48 ) ;
V_4 = F_21 ( V_43 ) ;
F_43 ( ! V_4 || ( V_4 -> V_23 != V_24 ) ) ;
V_43 = F_31 ( V_4 , V_43 ) ;
if ( ! V_43 )
return V_48 ;
V_45 = F_32 ( ( unsigned long ) V_47 , V_48 ,
V_43 , F_44 (unsigned long, cnt,
(tiop->minimum_bus_width / 8)) ) ;
F_42 ( L_8 , V_43 , V_45 ) ;
return 0 ;
}
int F_46 ( struct V_49 * V_50 , unsigned long V_33 )
{
T_7 V_51 ;
T_8 V_52 ;
int V_45 ;
if ( V_2 )
return 0 ;
if ( ! F_21 ( V_33 ) )
return 0 ;
F_43 ( F_47 ( V_50 ) ) ;
V_51 = F_48 () ;
F_49 ( V_53 ) ;
if ( F_50 ( & V_52 , ( void * ) ( V_50 -> V_54 ) ,
sizeof( V_52 ) ) ) {
F_49 ( V_51 ) ;
return 0 ;
}
V_45 = F_51 ( V_52 , V_50 ,
& V_55 , 1 , V_33 ) ;
F_49 ( V_51 ) ;
return V_45 == 0 ;
}
