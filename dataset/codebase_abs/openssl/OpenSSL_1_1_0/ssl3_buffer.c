void F_1 ( T_1 * V_1 , const unsigned char * V_2 , int V_3 )
{
if ( V_2 != NULL )
memcpy ( V_1 -> V_4 , V_2 , V_3 ) ;
V_1 -> V_5 = V_3 ;
V_1 -> V_6 = 0 ;
}
void F_2 ( T_1 * V_1 )
{
V_1 -> V_6 = 0 ;
V_1 -> V_5 = 0 ;
}
void F_3 ( T_1 * V_1 )
{
F_4 ( V_1 -> V_4 ) ;
V_1 -> V_4 = NULL ;
}
int F_5 ( T_2 * V_7 )
{
unsigned char * V_8 ;
T_3 V_9 , V_10 = 0 , V_11 ;
T_1 * V_1 ;
V_1 = F_6 ( & V_7 -> V_12 ) ;
if ( F_7 ( V_7 ) )
V_11 = V_13 ;
else
V_11 = V_14 ;
#if F_8 ( V_15 ) && V_15 != 0
V_10 = ( - V_14 ) & ( V_15 - 1 ) ;
#endif
if ( V_1 -> V_4 == NULL ) {
V_9 = V_16
+ V_17 + V_11 + V_10 ;
#ifndef F_9
if ( F_10 ( V_7 ) )
V_9 += V_18 ;
#endif
if ( V_1 -> V_19 > V_9 )
V_9 = V_1 -> V_19 ;
if ( ( V_8 = F_11 ( V_9 ) ) == NULL )
goto V_20;
V_1 -> V_4 = V_8 ;
V_1 -> V_9 = V_9 ;
}
F_12 ( & V_7 -> V_12 , & ( V_1 -> V_4 [ 0 ] ) ) ;
return 1 ;
V_20:
F_13 ( V_21 , V_22 ) ;
return 0 ;
}
int F_14 ( T_2 * V_7 , unsigned int V_23 , T_3 V_9 )
{
unsigned char * V_8 ;
T_3 V_10 = 0 , V_11 ;
T_1 * V_24 ;
unsigned int V_25 ;
V_7 -> V_12 . V_23 = V_23 ;
if ( V_9 == 0 ) {
if ( F_7 ( V_7 ) )
V_11 = V_13 + 1 ;
else
V_11 = V_14 ;
#if F_8 ( V_15 ) && V_15 != 0
V_10 = ( - V_14 ) & ( V_15 - 1 ) ;
#endif
V_9 = V_7 -> V_26
+ V_27 + V_11 + V_10 ;
#ifndef F_9
if ( F_10 ( V_7 ) )
V_9 += V_18 ;
#endif
if ( ! ( V_7 -> V_28 & V_29 ) )
V_9 += V_11 + V_10 + V_27 ;
}
V_24 = F_15 ( & V_7 -> V_12 ) ;
for ( V_25 = 0 ; V_25 < V_23 ; V_25 ++ ) {
if ( V_24 [ V_25 ] . V_4 == NULL ) {
if ( ( V_8 = F_11 ( V_9 ) ) == NULL ) {
V_7 -> V_12 . V_23 = V_25 ;
goto V_20;
}
V_24 [ V_25 ] . V_4 = V_8 ;
V_24 [ V_25 ] . V_9 = V_9 ;
}
}
return 1 ;
V_20:
F_13 ( V_30 , V_22 ) ;
return 0 ;
}
int F_16 ( T_2 * V_7 )
{
if ( ! F_5 ( V_7 ) )
return 0 ;
if ( ! F_14 ( V_7 , 1 , 0 ) )
return 0 ;
return 1 ;
}
int F_17 ( T_2 * V_7 )
{
T_1 * V_24 ;
unsigned int V_31 ;
V_31 = V_7 -> V_12 . V_23 ;
while ( V_31 > 0 ) {
V_24 = & F_15 ( & V_7 -> V_12 ) [ V_31 - 1 ] ;
F_4 ( V_24 -> V_4 ) ;
V_24 -> V_4 = NULL ;
V_31 -- ;
}
V_7 -> V_12 . V_23 = 0 ;
return 1 ;
}
int F_18 ( T_2 * V_7 )
{
T_1 * V_1 ;
V_1 = F_6 ( & V_7 -> V_12 ) ;
F_4 ( V_1 -> V_4 ) ;
V_1 -> V_4 = NULL ;
return 1 ;
}
