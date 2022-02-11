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
V_7 += F_4 ( ( V_6 -> V_17 - V_6 -> V_18 ) + 1 , V_14 ) ;
V_8 |= V_6 -> V_8 ;
}
if ( F_5 ( V_8 ) != 1 )
goto V_15;
V_13 = V_7 >> V_19 ;
if ( V_13 >= V_11 )
goto V_15;
for ( V_12 = 0 ; V_12 < V_13 ; V_12 ++ )
V_10 [ V_12 ] = F_6 ( V_4 ) ;
V_4 -> V_20 = F_7 ( V_10 , V_13 , V_21 , V_22 ) ;
if ( ! V_4 -> V_20 )
goto V_15;
V_7 = 0 ;
for ( V_12 = 0 ; V_12 < V_4 -> V_16 ; V_12 ++ ) {
V_6 = V_4 -> V_5 + V_12 ;
F_8 ( L_1 ,
( unsigned long ) ( V_4 -> V_20 + V_7 ) ,
V_6 -> V_8 & V_23 ? L_2 : L_3 ,
( unsigned long ) V_6 -> V_18 ) ;
V_7 += F_4 ( ( V_6 -> V_17 - V_6 -> V_18 ) + 1 , V_14 ) ;
}
V_4 -> V_24 = V_25 ;
F_9 ( & V_4 -> V_26 ) ;
F_10 ( & V_27 ) ;
#ifdef F_11
if ( V_8 & V_23 )
F_12 ( & V_4 -> V_26 , & V_3 ) ;
#endif
#ifdef F_13
if ( V_8 & V_28 )
F_12 ( & V_4 -> V_26 , & V_29 ) ;
#endif
F_14 ( & V_27 ) ;
return 0 ;
V_15:
F_15 ( L_4 ) ;
return - 1 ;
}
void T_2 * F_16 ( struct V_30 * V_26 ,
unsigned long V_31 ,
unsigned long V_32 )
{
unsigned long V_33 ;
struct V_3 * V_4 ;
struct V_5 * V_6 ;
int V_12 , V_7 ;
unsigned long V_8 ;
F_17 ( & V_27 , V_8 ) ;
F_18 (tiop, list, list) {
V_33 = 0 ;
for ( V_12 = 0 ; V_12 < V_4 -> V_16 ; V_12 ++ ) {
V_6 = V_4 -> V_5 + V_12 ;
if ( V_6 -> V_18 == V_31 ) {
F_19 ( & V_27 , V_8 ) ;
return V_4 -> V_20 + V_33 ;
}
V_7 = ( V_6 -> V_17 - V_6 -> V_18 ) + 1 ;
V_33 += F_4 ( V_7 , V_14 ) ;
}
}
F_19 ( & V_27 , V_8 ) ;
return NULL ;
}
static struct V_3 * F_20 ( unsigned long V_34 )
{
T_3 * V_35 ;
T_4 * V_36 ;
T_5 * V_37 ;
T_6 * V_38 ;
T_6 V_39 ;
V_35 = V_40 + F_21 ( V_34 ) ;
if ( ! F_22 ( * V_35 ) )
return NULL ;
V_36 = F_23 ( V_35 , V_34 ) ;
if ( ! F_24 ( * V_36 ) )
return NULL ;
V_37 = F_25 ( V_36 , V_34 ) ;
if ( ! F_26 ( * V_37 ) )
return NULL ;
V_38 = F_27 ( V_37 , V_34 ) ;
V_39 = * V_38 ;
return F_28 ( F_29 ( V_39 ) ) ;
}
static unsigned long F_30 ( struct V_3 * V_4 ,
unsigned long V_34 )
{
struct V_5 * V_6 ;
unsigned long V_41 = ( unsigned long ) V_4 -> V_20 ;
unsigned long V_7 ;
int V_12 ;
for ( V_12 = 0 ; V_12 < V_4 -> V_16 ; V_12 ++ ) {
V_6 = V_4 -> V_5 + V_12 ;
V_7 = F_4 ( ( V_6 -> V_17 - V_6 -> V_18 ) + 1 , V_14 ) ;
if ( V_34 < ( V_41 + V_7 ) )
return V_6 -> V_18 + ( V_34 - V_41 ) ;
V_41 += V_7 ;
}
return 0 ;
}
static unsigned long long F_31 ( unsigned long V_42 , int V_43 ,
unsigned long V_44 , int V_45 )
{
unsigned long long V_46 = 0 ;
switch ( V_43 ) {
case 1 :
V_46 = F_32 ( V_42 ) ;
break;
case 2 :
V_46 = F_33 ( V_42 ) ;
break;
case 4 :
V_46 = F_34 ( V_42 ) ;
break;
case 8 :
V_46 = F_35 ( V_42 ) ;
break;
}
switch ( V_45 ) {
case 1 :
F_36 ( V_46 , V_44 ) ;
break;
case 2 :
F_37 ( V_46 , V_44 ) ;
break;
case 4 :
F_38 ( V_46 , V_44 ) ;
break;
case 8 :
F_39 ( V_46 , V_44 ) ;
break;
}
return V_46 ;
}
static unsigned long F_40 ( void * V_47 , const void * V_48 , unsigned long V_49 )
{
struct V_3 * V_4 ;
unsigned long V_42 = ( unsigned long ) V_48 ;
unsigned long long V_46 ;
F_41 ( L_5 , V_42 , V_49 ) ;
V_4 = F_20 ( V_42 ) ;
F_42 ( ! V_4 || ( V_4 -> V_24 != V_25 ) ) ;
V_42 = F_30 ( V_4 , V_42 ) ;
if ( ! V_42 )
return V_49 ;
V_46 = F_31 ( V_42 ,
F_43 (unsigned long, cnt,
(tiop->minimum_bus_width / 8)) ,
( unsigned long ) V_47 , V_49 ) ;
F_41 ( L_6 , V_42 , V_46 ) ;
return 0 ;
}
static unsigned long F_44 ( void * V_47 , const void * V_48 , unsigned long V_49 )
{
struct V_3 * V_4 ;
unsigned long V_44 = ( unsigned long ) V_47 ;
unsigned long long V_46 ;
F_41 ( L_7 , V_44 , V_49 ) ;
V_4 = F_20 ( V_44 ) ;
F_42 ( ! V_4 || ( V_4 -> V_24 != V_25 ) ) ;
V_44 = F_30 ( V_4 , V_44 ) ;
if ( ! V_44 )
return V_49 ;
V_46 = F_31 ( ( unsigned long ) V_48 , V_49 ,
V_44 , F_43 (unsigned long, cnt,
(tiop->minimum_bus_width / 8)) ) ;
F_41 ( L_8 , V_44 , V_46 ) ;
return 0 ;
}
int F_45 ( struct V_50 * V_51 , unsigned long V_34 )
{
T_7 V_52 ;
T_8 V_53 ;
int V_46 ;
if ( V_2 )
return 0 ;
if ( ! F_20 ( V_34 ) )
return 0 ;
F_42 ( F_46 ( V_51 ) ) ;
V_52 = F_47 () ;
F_48 ( V_54 ) ;
if ( F_49 ( & V_53 , ( void * ) ( V_51 -> V_55 ) ,
sizeof( V_53 ) ) ) {
F_48 ( V_52 ) ;
return 0 ;
}
V_46 = F_50 ( V_53 , V_51 ,
& V_56 , 1 , V_34 ) ;
F_48 ( V_52 ) ;
return V_46 == 0 ;
}
