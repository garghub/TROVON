static void * T_1 F_1 ( int V_1 ,
unsigned long V_2 ,
unsigned long V_3 ,
unsigned long V_4 )
{
return F_2 ( F_3 ( V_1 ) , V_2 , V_3 , V_4 ) ;
}
void * T_2 F_4 ( unsigned long V_2 , int V_1 )
{
if ( F_5 () ) {
struct V_5 * V_5 ;
if ( F_6 ( V_1 , V_6 ) )
V_5 = F_7 (
V_1 , V_7 | V_8 | V_9 ,
F_8 ( V_2 ) ) ;
else
V_5 = F_9 (
V_7 | V_8 | V_9 ,
F_8 ( V_2 ) ) ;
if ( V_5 )
return F_10 ( V_5 ) ;
return NULL ;
} else
return F_1 ( V_1 , V_2 , V_2 ,
F_11 ( V_10 ) ) ;
}
void * T_2 F_12 ( unsigned long V_2 , int V_1 )
{
void * V_11 ;
if ( ! V_12 )
return F_4 ( V_2 , V_1 ) ;
V_11 = ( void * ) F_13 ( ( unsigned long ) V_12 , V_2 ) ;
if ( V_11 + V_2 > V_13 )
return F_4 ( V_2 , V_1 ) ;
V_12 = V_11 + V_2 ;
return V_11 ;
}
void T_2 F_14 ( T_3 * V_14 , int V_1 ,
unsigned long V_15 , unsigned long V_16 )
{
unsigned long V_17 = F_15 ( * V_14 ) ;
int V_18 = F_16 ( V_17 ) ;
if ( F_17 ( V_18 , V_1 ) > V_19 )
F_18 ( V_20 L_1
L_2 , V_15 , V_16 - 1 ) ;
}
T_3 * T_2 F_19 ( T_4 * V_21 , unsigned long V_22 , int V_1 )
{
T_3 * V_14 = F_20 ( V_21 , V_22 ) ;
if ( F_21 ( * V_14 ) ) {
T_3 V_23 ;
void * V_24 = F_12 ( V_25 , V_1 ) ;
if ( ! V_24 )
return NULL ;
V_23 = F_22 ( F_11 ( V_24 ) >> V_26 , V_27 ) ;
F_23 ( & V_28 , V_22 , V_14 , V_23 ) ;
}
return V_14 ;
}
T_4 * T_2 F_24 ( T_5 * V_29 , unsigned long V_22 , int V_1 )
{
T_4 * V_21 = F_25 ( V_29 , V_22 ) ;
if ( F_26 ( * V_21 ) ) {
void * V_24 = F_4 ( V_25 , V_1 ) ;
if ( ! V_24 )
return NULL ;
F_27 ( & V_28 , V_21 , V_24 ) ;
}
return V_21 ;
}
T_5 * T_2 F_28 ( T_6 * V_30 , unsigned long V_22 , int V_1 )
{
T_5 * V_29 = F_29 ( V_30 , V_22 ) ;
if ( F_30 ( * V_29 ) ) {
void * V_24 = F_4 ( V_25 , V_1 ) ;
if ( ! V_24 )
return NULL ;
F_31 ( & V_28 , V_29 , V_24 ) ;
}
return V_29 ;
}
T_6 * T_2 F_32 ( unsigned long V_22 , int V_1 )
{
T_6 * V_30 = F_33 ( V_22 ) ;
if ( F_34 ( * V_30 ) ) {
void * V_24 = F_4 ( V_25 , V_1 ) ;
if ( ! V_24 )
return NULL ;
F_35 ( & V_28 , V_30 , V_24 ) ;
}
return V_30 ;
}
int T_2 F_36 ( unsigned long V_15 ,
unsigned long V_16 , int V_1 )
{
unsigned long V_22 = V_15 ;
T_6 * V_30 ;
T_5 * V_29 ;
T_4 * V_21 ;
T_3 * V_14 ;
for (; V_22 < V_16 ; V_22 += V_25 ) {
V_30 = F_32 ( V_22 , V_1 ) ;
if ( ! V_30 )
return - V_31 ;
V_29 = F_28 ( V_30 , V_22 , V_1 ) ;
if ( ! V_29 )
return - V_31 ;
V_21 = F_24 ( V_29 , V_22 , V_1 ) ;
if ( ! V_21 )
return - V_31 ;
V_14 = F_19 ( V_21 , V_22 , V_1 ) ;
if ( ! V_14 )
return - V_31 ;
F_14 ( V_14 , V_1 , V_22 , V_22 + V_25 ) ;
}
return 0 ;
}
struct V_5 * T_2 F_37 ( unsigned long V_32 , int V_33 )
{
unsigned long V_15 ;
unsigned long V_16 ;
struct V_5 * V_34 ;
V_34 = F_38 ( V_32 * V_35 ) ;
V_15 = ( unsigned long ) V_34 ;
V_16 = ( unsigned long ) ( V_34 + V_35 ) ;
if ( F_39 ( V_15 , V_16 , V_33 ) )
return NULL ;
return V_34 ;
}
void T_7 F_40 ( struct V_5 * * V_36 ,
unsigned long V_37 ,
unsigned long V_38 ,
unsigned long V_39 , int V_40 )
{
unsigned long V_32 ;
unsigned long V_2 = sizeof( struct V_5 ) * V_35 ;
void * V_41 ;
V_2 = F_13 ( V_2 , V_42 ) ;
V_41 = F_1 ( V_40 , V_2 * V_39 ,
V_42 , F_11 ( V_10 ) ) ;
if ( V_41 ) {
V_12 = V_41 ;
V_13 = V_41 + V_2 * V_39 ;
}
for ( V_32 = V_37 ; V_32 < V_38 ; V_32 ++ ) {
struct V_43 * V_44 ;
if ( ! F_41 ( V_32 ) )
continue;
V_36 [ V_32 ] = F_37 ( V_32 , V_40 ) ;
if ( V_36 [ V_32 ] )
continue;
V_44 = F_42 ( V_32 ) ;
F_18 ( V_45 L_3
L_4 , V_46 ) ;
V_44 -> V_47 = 0 ;
}
if ( V_41 ) {
F_43 ( F_11 ( V_12 ) , V_13 - V_12 ) ;
V_12 = NULL ;
V_13 = NULL ;
}
}
