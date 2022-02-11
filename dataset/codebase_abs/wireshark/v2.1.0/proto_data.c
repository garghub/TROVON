static T_1
F_1 ( T_2 V_1 , T_2 V_2 )
{
const T_3 * V_3 = ( const T_3 * ) V_1 ;
const T_3 * V_4 = ( const T_3 * ) V_2 ;
if ( V_3 -> V_5 > V_4 -> V_5 ) {
return 1 ;
} else if ( V_3 -> V_5 == V_4 -> V_5 ) {
if ( V_3 -> V_6 > V_4 -> V_6 ) {
return 1 ;
} else if ( V_3 -> V_6 == V_4 -> V_6 ) {
return 0 ;
}
return - 1 ;
} else {
return - 1 ;
}
}
void
F_2 ( T_4 * V_7 , struct V_8 * V_9 , int V_5 , T_5 V_6 , void * V_10 )
{
T_3 * V_11 ;
T_6 * * V_12 ;
T_4 * V_13 ;
if ( V_7 == V_9 -> V_14 ) {
V_13 = V_7 ;
V_12 = & V_9 -> V_10 ;
} else {
V_13 = F_3 () ;
V_12 = & V_9 -> V_15 -> V_16 ;
}
V_11 = ( T_3 * ) F_4 ( V_13 , sizeof( T_3 ) ) ;
V_11 -> V_5 = V_5 ;
V_11 -> V_6 = V_6 ;
V_11 -> V_10 = V_10 ;
* V_12 = F_5 ( * V_12 , V_11 ) ;
}
void *
F_6 ( T_4 * V_13 , struct V_8 * V_9 , int V_5 , T_5 V_6 )
{
T_3 V_17 , * V_11 ;
T_6 * V_18 ;
V_17 . V_5 = V_5 ;
V_17 . V_6 = V_6 ;
V_17 . V_10 = NULL ;
if ( V_13 == V_9 -> V_14 ) {
V_18 = F_7 ( V_9 -> V_10 , & V_17 , F_1 ) ;
} else {
V_18 = F_7 ( V_9 -> V_15 -> V_16 , & V_17 , F_1 ) ;
}
if ( V_18 ) {
V_11 = ( T_3 * ) V_18 -> V_19 ;
return V_11 -> V_10 ;
}
return NULL ;
}
void
F_8 ( T_4 * V_13 , struct V_8 * V_9 , int V_5 , T_5 V_6 )
{
T_3 V_17 ;
T_6 * V_18 ;
T_6 * * V_12 ;
V_17 . V_5 = V_5 ;
V_17 . V_6 = V_6 ;
V_17 . V_10 = NULL ;
if ( V_13 == V_9 -> V_14 ) {
V_18 = F_7 ( V_9 -> V_15 -> V_16 , & V_17 , F_1 ) ;
V_12 = & V_9 -> V_10 ;
} else {
V_18 = F_7 ( V_9 -> V_15 -> V_16 , & V_17 , F_1 ) ;
V_12 = & V_9 -> V_15 -> V_16 ;
}
if ( V_18 ) {
* V_12 = F_9 ( * V_12 , V_18 -> V_19 ) ;
}
}
T_7 *
F_10 ( T_4 * V_13 , struct V_8 * V_9 , T_8 V_20 ) {
T_3 * V_17 ;
if ( V_13 == V_9 -> V_14 ) {
V_17 = ( T_3 * ) F_11 ( V_9 -> V_10 , V_20 ) ;
} else {
V_17 = ( T_3 * ) F_11 ( V_9 -> V_15 -> V_16 , V_20 ) ;
}
return F_12 ( F_13 () , L_1 , F_14 ( V_17 -> V_5 ) , V_17 -> V_6 ) ;
}
