static int
F_1 ( struct V_1 * V_2 , unsigned int V_3 , int V_4 , void * V_5 )
{
T_1 * V_6 = ( T_1 * ) V_5 ;
int V_7 = 0 ;
if ( V_5 == NULL ) {
F_2 ( ( L_1 , F_3 ( V_2 ) ) ) ;
return - V_8 ;
}
F_2 ( ( L_2 , F_3 ( V_2 ) , V_3 , V_4 ) ) ;
if ( V_6 -> V_9 < V_10 ) return - V_8 ;
F_2 ( ( L_3 , V_6 -> V_9 ) ) ;
return V_7 ;
}
static int
F_4 ( struct V_1 * V_2 , unsigned int V_3 , int V_4 , void * V_5 , unsigned long * V_11 )
{
T_1 * V_6 = ( T_1 * ) V_5 ;
* V_11 = V_6 -> V_9 ;
return 0 ;
}
static int
F_5 ( struct V_1 * V_2 , void * V_12 , unsigned int V_3 , int V_4 , void * V_5 )
{
T_2 * V_13 ;
T_1 * V_6 = ( T_1 * ) V_5 ;
V_13 = ( T_2 * ) V_12 ;
V_13 -> V_14 = V_15 ;
V_13 -> V_16 = V_6 -> V_9 ;
V_13 -> V_17 = sizeof( * V_13 ) ;
V_13 -> V_18 = 0UL ;
V_13 -> V_19 = 0UL ;
F_2 ( ( L_4 ,
F_3 ( V_2 ) ,
V_12 ,
V_13 -> V_16 ,
sizeof( * V_13 ) ,
V_13 -> V_14 ,
V_13 -> V_17 ) ) ;
return 0 ;
}
static int
F_6 ( struct V_1 * V_2 , void * V_12 , T_3 * V_6 , struct V_20 * V_21 , unsigned long V_22 )
{
T_2 * V_13 ;
T_4 * V_23 ;
void * V_24 , * V_25 ;
unsigned long * V_26 , V_27 ;
unsigned int V_28 , V_29 ;
unsigned char V_30 ;
unsigned char V_31 ;
if ( F_7 ( V_12 == NULL || V_6 == NULL || V_21 == NULL || V_2 == NULL ) ) {
F_2 ( ( L_5 , V_2 -> V_32 , V_12 , V_6 ) ) ;
return - V_8 ;
}
V_13 = ( T_2 * ) V_12 ;
V_24 = V_12 + V_13 -> V_17 ;
V_25 = V_12 + V_13 -> V_16 ;
V_30 = V_6 -> V_30 ;
V_31 = V_6 -> V_31 ;
if ( ( V_25 - V_24 ) < V_33 ) goto V_34;
V_28 = F_8 ( V_6 -> V_35 [ 0 ] ) ;
V_23 = ( T_4 * ) V_24 ;
F_9 ( V_6 -> V_36 ) ;
V_27 = sizeof( * V_23 ) + ( V_28 << 3 ) ;
V_26 = ( unsigned long * ) ( V_23 + 1 ) ;
V_13 -> V_19 ++ ;
F_10 ( ( L_6 ,
V_2 -> V_32 ,
V_13 -> V_19 ,
V_24 , V_25 ,
V_25 - V_24 ,
V_30 ,
V_31 , V_28 ) ) ;
V_23 -> V_32 = V_37 -> V_32 ;
V_23 -> V_30 = V_30 ;
V_23 -> V_38 = V_6 -> V_39 ;
V_23 -> V_40 = V_21 -> V_41 | ( ( V_21 -> V_42 >> 41 ) & 0x3 ) ;
V_23 -> V_43 = V_22 ;
V_23 -> V_4 = F_11 () ;
V_23 -> V_44 = V_6 -> V_45 ;
V_23 -> V_46 = V_37 -> V_46 ;
if ( V_28 ) {
unsigned long * V_47 = V_6 -> V_36 ;
for( V_29 = 0 ; V_29 < V_28 ; V_29 ++ ) {
* V_26 ++ = * V_47 ++ ;
}
}
V_13 -> V_17 += V_27 ;
V_24 += V_27 ;
if ( ( V_25 - V_24 ) < V_33 ) goto V_34;
V_6 -> V_48 . V_49 . V_50 = 0 ;
V_6 -> V_48 . V_49 . V_51 = 0 ;
V_6 -> V_48 . V_49 . V_52 = 0 ;
V_6 -> V_48 . V_49 . V_53 = 1 ;
return 0 ;
V_34:
F_10 ( ( L_7 , V_25 - V_24 , V_13 -> V_19 , V_31 ) ) ;
V_13 -> V_18 ++ ;
if ( V_31 == 0 ) {
V_6 -> V_48 . V_49 . V_50 = 0 ;
V_6 -> V_48 . V_49 . V_51 = 0 ;
V_6 -> V_48 . V_49 . V_52 = 1 ;
V_6 -> V_48 . V_49 . V_53 = 0 ;
} else {
V_6 -> V_48 . V_49 . V_50 = 1 ;
V_6 -> V_48 . V_49 . V_51 = 1 ;
V_6 -> V_48 . V_49 . V_52 = 1 ;
V_6 -> V_48 . V_49 . V_53 = 0 ;
}
return - 1 ;
}
static int
F_12 ( struct V_1 * V_2 , T_5 * V_54 , void * V_12 , struct V_20 * V_21 )
{
T_2 * V_13 ;
V_13 = ( T_2 * ) V_12 ;
V_13 -> V_19 = 0UL ;
V_13 -> V_17 = sizeof( * V_13 ) ;
V_54 -> V_49 . V_52 = 0 ;
V_54 -> V_49 . V_53 = 1 ;
return 0 ;
}
static int
F_13 ( struct V_1 * V_2 , void * V_12 , struct V_20 * V_21 )
{
F_2 ( ( L_8 , F_3 ( V_2 ) , V_12 ) ) ;
return 0 ;
}
static int T_6
F_14 ( void )
{
int V_7 ;
V_7 = F_15 ( & V_55 ) ;
if ( V_7 == 0 ) {
F_16 ( L_9 ,
V_55 . V_56 ,
V_57 ,
V_58 ) ;
} else {
F_16 ( L_10 ,
V_55 . V_56 ,
V_7 ) ;
}
return V_7 ;
}
static void T_7
F_17 ( void )
{
int V_7 ;
V_7 = F_18 ( V_55 . V_59 ) ;
F_16 ( L_11 , V_55 . V_56 , V_7 ) ;
}
