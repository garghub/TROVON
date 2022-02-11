static void * T_1 F_1 ( int V_1 ,
unsigned long V_2 ,
unsigned long V_3 ,
unsigned long V_4 )
{
return F_2 ( V_2 , V_3 , V_4 ,
V_5 , V_1 ) ;
}
void * T_2 F_3 ( unsigned long V_2 , int V_1 )
{
if ( F_4 () ) {
struct V_6 * V_6 ;
if ( F_5 ( V_1 , V_7 ) )
V_6 = F_6 (
V_1 , V_8 | V_9 | V_10 ,
F_7 ( V_2 ) ) ;
else
V_6 = F_8 (
V_8 | V_9 | V_10 ,
F_7 ( V_2 ) ) ;
if ( V_6 )
return F_9 ( V_6 ) ;
return NULL ;
} else
return F_1 ( V_1 , V_2 , V_2 ,
F_10 ( V_11 ) ) ;
}
void * T_2 F_11 ( unsigned long V_2 , int V_1 )
{
void * V_12 ;
if ( ! V_13 )
return F_3 ( V_2 , V_1 ) ;
V_12 = ( void * ) F_12 ( ( unsigned long ) V_13 , V_2 ) ;
if ( V_12 + V_2 > V_14 )
return F_3 ( V_2 , V_1 ) ;
V_13 = V_12 + V_2 ;
return V_12 ;
}
void T_2 F_13 ( T_3 * V_15 , int V_1 ,
unsigned long V_16 , unsigned long V_17 )
{
unsigned long V_18 = F_14 ( * V_15 ) ;
int V_19 = F_15 ( V_18 ) ;
if ( F_16 ( V_19 , V_1 ) > V_20 )
F_17 ( V_21 L_1
L_2 , V_16 , V_17 - 1 ) ;
}
T_3 * T_2 F_18 ( T_4 * V_22 , unsigned long V_23 , int V_1 )
{
T_3 * V_15 = F_19 ( V_22 , V_23 ) ;
if ( F_20 ( * V_15 ) ) {
T_3 V_24 ;
void * V_25 = F_11 ( V_26 , V_1 ) ;
if ( ! V_25 )
return NULL ;
V_24 = F_21 ( F_10 ( V_25 ) >> V_27 , V_28 ) ;
F_22 ( & V_29 , V_23 , V_15 , V_24 ) ;
}
return V_15 ;
}
T_4 * T_2 F_23 ( T_5 * V_30 , unsigned long V_23 , int V_1 )
{
T_4 * V_22 = F_24 ( V_30 , V_23 ) ;
if ( F_25 ( * V_22 ) ) {
void * V_25 = F_3 ( V_26 , V_1 ) ;
if ( ! V_25 )
return NULL ;
F_26 ( & V_29 , V_22 , V_25 ) ;
}
return V_22 ;
}
T_5 * T_2 F_27 ( T_6 * V_31 , unsigned long V_23 , int V_1 )
{
T_5 * V_30 = F_28 ( V_31 , V_23 ) ;
if ( F_29 ( * V_30 ) ) {
void * V_25 = F_3 ( V_26 , V_1 ) ;
if ( ! V_25 )
return NULL ;
F_30 ( & V_29 , V_30 , V_25 ) ;
}
return V_30 ;
}
T_6 * T_2 F_31 ( unsigned long V_23 , int V_1 )
{
T_6 * V_31 = F_32 ( V_23 ) ;
if ( F_33 ( * V_31 ) ) {
void * V_25 = F_3 ( V_26 , V_1 ) ;
if ( ! V_25 )
return NULL ;
F_34 ( & V_29 , V_31 , V_25 ) ;
}
return V_31 ;
}
int T_2 F_35 ( unsigned long V_16 ,
unsigned long V_17 , int V_1 )
{
unsigned long V_23 = V_16 ;
T_6 * V_31 ;
T_5 * V_30 ;
T_4 * V_22 ;
T_3 * V_15 ;
for (; V_23 < V_17 ; V_23 += V_26 ) {
V_31 = F_31 ( V_23 , V_1 ) ;
if ( ! V_31 )
return - V_32 ;
V_30 = F_27 ( V_31 , V_23 , V_1 ) ;
if ( ! V_30 )
return - V_32 ;
V_22 = F_23 ( V_30 , V_23 , V_1 ) ;
if ( ! V_22 )
return - V_32 ;
V_15 = F_18 ( V_22 , V_23 , V_1 ) ;
if ( ! V_15 )
return - V_32 ;
F_13 ( V_15 , V_1 , V_23 , V_23 + V_26 ) ;
}
return 0 ;
}
struct V_6 * T_2 F_36 ( unsigned long V_33 , int V_34 )
{
unsigned long V_16 ;
unsigned long V_17 ;
struct V_6 * V_35 ;
V_35 = F_37 ( V_33 * V_36 ) ;
V_16 = ( unsigned long ) V_35 ;
V_17 = ( unsigned long ) ( V_35 + V_36 ) ;
if ( F_38 ( V_16 , V_17 , V_34 ) )
return NULL ;
return V_35 ;
}
void T_7 F_39 ( struct V_6 * * V_37 ,
unsigned long V_38 ,
unsigned long V_39 ,
unsigned long V_40 , int V_41 )
{
unsigned long V_33 ;
unsigned long V_2 = sizeof( struct V_6 ) * V_36 ;
void * V_42 ;
V_2 = F_12 ( V_2 , V_43 ) ;
V_42 = F_1 ( V_41 , V_2 * V_40 ,
V_43 , F_10 ( V_11 ) ) ;
if ( V_42 ) {
V_13 = V_42 ;
V_14 = V_42 + V_2 * V_40 ;
}
for ( V_33 = V_38 ; V_33 < V_39 ; V_33 ++ ) {
struct V_44 * V_45 ;
if ( ! F_40 ( V_33 ) )
continue;
V_37 [ V_33 ] = F_36 ( V_33 , V_41 ) ;
if ( V_37 [ V_33 ] )
continue;
V_45 = F_41 ( V_33 ) ;
F_17 ( V_46 L_3
L_4 , V_47 ) ;
V_45 -> V_48 = 0 ;
}
if ( V_42 ) {
F_42 ( F_10 ( V_13 ) ,
V_14 - V_13 ) ;
V_13 = NULL ;
V_14 = NULL ;
}
}
