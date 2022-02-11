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
V_5 = F_7 ( V_1 ,
V_7 | V_8 , F_8 ( V_2 ) ) ;
else
V_5 = F_9 ( V_7 | V_8 ,
F_8 ( V_2 ) ) ;
if ( V_5 )
return F_10 ( V_5 ) ;
return NULL ;
} else
return F_1 ( V_1 , V_2 , V_2 ,
F_11 ( V_9 ) ) ;
}
void * T_2 F_12 ( unsigned long V_2 , int V_1 )
{
void * V_10 ;
if ( ! V_11 )
return F_4 ( V_2 , V_1 ) ;
V_10 = ( void * ) F_13 ( ( unsigned long ) V_11 , V_2 ) ;
if ( V_10 + V_2 > V_12 )
return F_4 ( V_2 , V_1 ) ;
V_11 = V_10 + V_2 ;
return V_10 ;
}
void T_2 F_14 ( T_3 * V_13 , int V_1 ,
unsigned long V_14 , unsigned long V_15 )
{
unsigned long V_16 = F_15 ( * V_13 ) ;
int V_17 = F_16 ( V_16 ) ;
if ( F_17 ( V_17 , V_1 ) > V_18 )
F_18 ( V_19 L_1
L_2 , V_14 , V_15 - 1 ) ;
}
T_3 * T_2 F_19 ( T_4 * V_20 , unsigned long V_21 , int V_1 )
{
T_3 * V_13 = F_20 ( V_20 , V_21 ) ;
if ( F_21 ( * V_13 ) ) {
T_3 V_22 ;
void * V_23 = F_12 ( V_24 , V_1 ) ;
if ( ! V_23 )
return NULL ;
V_22 = F_22 ( F_11 ( V_23 ) >> V_25 , V_26 ) ;
F_23 ( & V_27 , V_21 , V_13 , V_22 ) ;
}
return V_13 ;
}
T_4 * T_2 F_24 ( T_5 * V_28 , unsigned long V_21 , int V_1 )
{
T_4 * V_20 = F_25 ( V_28 , V_21 ) ;
if ( F_26 ( * V_20 ) ) {
void * V_23 = F_4 ( V_24 , V_1 ) ;
if ( ! V_23 )
return NULL ;
F_27 ( & V_27 , V_20 , V_23 ) ;
}
return V_20 ;
}
T_5 * T_2 F_28 ( T_6 * V_29 , unsigned long V_21 , int V_1 )
{
T_5 * V_28 = F_29 ( V_29 , V_21 ) ;
if ( F_30 ( * V_28 ) ) {
void * V_23 = F_4 ( V_24 , V_1 ) ;
if ( ! V_23 )
return NULL ;
F_31 ( & V_27 , V_28 , V_23 ) ;
}
return V_28 ;
}
T_6 * T_2 F_32 ( unsigned long V_21 , int V_1 )
{
T_6 * V_29 = F_33 ( V_21 ) ;
if ( F_34 ( * V_29 ) ) {
void * V_23 = F_4 ( V_24 , V_1 ) ;
if ( ! V_23 )
return NULL ;
F_35 ( & V_27 , V_29 , V_23 ) ;
}
return V_29 ;
}
int T_2 F_36 ( struct V_5 * V_30 ,
unsigned long V_2 , int V_1 )
{
unsigned long V_21 = ( unsigned long ) V_30 ;
unsigned long V_15 = ( unsigned long ) ( V_30 + V_2 ) ;
T_6 * V_29 ;
T_5 * V_28 ;
T_4 * V_20 ;
T_3 * V_13 ;
for (; V_21 < V_15 ; V_21 += V_24 ) {
V_29 = F_32 ( V_21 , V_1 ) ;
if ( ! V_29 )
return - V_31 ;
V_28 = F_28 ( V_29 , V_21 , V_1 ) ;
if ( ! V_28 )
return - V_31 ;
V_20 = F_24 ( V_28 , V_21 , V_1 ) ;
if ( ! V_20 )
return - V_31 ;
V_13 = F_19 ( V_20 , V_21 , V_1 ) ;
if ( ! V_13 )
return - V_31 ;
F_14 ( V_13 , V_1 , V_21 , V_21 + V_24 ) ;
}
return 0 ;
}
struct V_5 * T_2 F_37 ( unsigned long V_32 , int V_33 )
{
struct V_5 * V_34 = F_38 ( V_32 * V_35 ) ;
int error = F_39 ( V_34 , V_35 , V_33 ) ;
if ( error )
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
V_42 , F_11 ( V_9 ) ) ;
if ( V_41 ) {
V_11 = V_41 ;
V_12 = V_41 + V_2 * V_39 ;
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
F_43 ( F_11 ( V_11 ) , V_12 - V_11 ) ;
V_11 = NULL ;
V_12 = NULL ;
}
}
