struct V_1 *
F_1 ( char * V_2 , int V_3 , int V_4 ,
struct V_5 * V_6 )
{
unsigned long V_7 ;
struct V_1 * V_8 ;
char * V_9 ;
int V_10 ;
F_2 ( V_2 == NULL || V_4 > V_11 ||
( V_3 * sizeof( struct V_12 ) ) > V_11 ) ;
V_10 = ( sizeof( struct V_1 ) + 7L ) & - 8L ;
if ( V_3 > 0 )
V_10 += V_3 * sizeof( struct V_12 ) ;
if ( V_4 > 0 )
V_10 += V_4 ;
F_3 ( & V_6 -> V_13 , V_7 ) ;
V_8 = (struct V_1 * )
F_4 ( & V_6 -> V_14 , V_10 ) ;
F_5 ( & V_6 -> V_13 , V_7 ) ;
if ( V_8 == NULL )
return F_6 ( - V_15 ) ;
memset ( V_8 , 0 , sizeof( struct V_1 ) ) ;
F_7 ( & V_8 -> V_16 ) ;
F_7 ( & V_8 -> V_17 ) ;
V_9 = ( char * ) V_8 + ( ( sizeof( struct V_1 ) + 7L ) & - 8L ) ;
V_8 -> V_18 = NULL ;
if ( V_3 > 0 ) {
V_8 -> V_18 = (struct V_12 * ) V_9 ;
V_9 += V_3 * sizeof( struct V_12 ) ;
memset ( V_8 -> V_18 , 0 , V_3 * sizeof( struct V_12 ) ) ;
}
V_8 -> V_9 = NULL ;
if ( V_4 > 0 ) {
V_8 -> V_9 = V_9 ;
memset ( V_8 -> V_9 , 0 , V_4 ) ;
}
strncpy ( ( char * ) & V_8 -> V_2 , V_2 , 4 ) ;
F_8 ( ( char * ) & V_8 -> V_2 , 4 ) ;
F_9 ( V_19 , & V_8 -> V_7 ) ;
F_10 ( V_6 ) ;
return V_8 ;
}
void
F_11 ( struct V_1 * V_8 , struct V_5 * V_6 )
{
unsigned long V_7 ;
F_3 ( & V_6 -> V_13 , V_7 ) ;
F_12 ( & V_6 -> V_14 , V_8 ) ;
F_5 ( & V_6 -> V_13 , V_7 ) ;
F_13 ( & V_6 -> V_20 ) ;
}
struct V_1 *
F_14 ( struct V_1 * V_8 )
{
struct V_5 * V_6 ;
V_6 = V_8 -> V_21 ;
if ( V_8 -> V_22 > 0 ) {
F_15 ( V_23 , V_6 ,
L_1 ,
V_8 -> V_22 ) ;
if ( ! F_16 ( V_24 , & V_8 -> V_7 ) )
V_8 -> V_25 = V_6 -> V_26 . V_27 ;
V_8 -> V_28 = V_29 ;
} else {
F_17 ( L_2 ,
F_18 ( & V_6 -> V_30 -> V_31 ) ) ;
V_8 -> V_28 = V_32 ;
V_8 -> V_33 = F_19 () ;
}
return V_8 ;
}
struct V_1 * F_20 ( struct V_1 * V_8 )
{
int V_34 ;
unsigned long long V_35 , V_33 ;
struct V_5 * V_21 ;
F_2 ( V_8 -> V_36 == NULL || V_8 -> V_37 == NULL ) ;
V_34 = V_8 -> V_28 == V_38 ;
V_35 = V_8 -> V_35 ;
V_33 = V_8 -> V_33 ;
V_21 = V_8 -> V_21 ;
while ( V_8 -> V_36 != NULL ) {
struct V_1 * V_36 ;
V_36 = V_8 -> V_36 ;
F_21 ( & V_8 -> V_17 ) ;
F_11 ( V_8 , V_8 -> V_39 ) ;
V_8 = V_36 ;
}
V_8 -> V_35 = V_35 ;
V_8 -> V_33 = V_33 ;
V_8 -> V_21 = V_21 ;
if ( V_34 )
V_8 -> V_28 = V_38 ;
else {
V_8 -> V_28 = V_32 ;
V_8 -> V_33 = F_19 () ;
}
return V_8 ;
}
void
F_22 ( struct V_1 * V_8 , struct V_40 * V_40 )
{
struct V_5 * V_6 ;
V_6 = V_8 -> V_21 ;
if ( V_8 -> V_41 == - V_42 ) {
F_23 ( & V_6 -> V_30 -> V_31 ,
L_3 , V_8 ) ;
return;
}
if ( V_8 -> V_41 == - V_43 ) {
F_23 ( & V_6 -> V_30 -> V_31 ,
L_4 , V_8 ) ;
return;
}
if ( V_6 -> V_44 && V_6 -> V_44 -> V_45 )
V_6 -> V_44 -> V_45 ( V_6 , V_8 , V_40 ) ;
}
void
F_24 ( struct V_1 * V_8 , struct V_40 * V_40 )
{
struct V_5 * V_6 ;
V_6 = V_8 -> V_21 ;
if ( V_6 -> V_44 && V_6 -> V_44 -> V_46 )
V_6 -> V_44 -> V_46 ( V_6 , V_40 , L_5 ) ;
}
