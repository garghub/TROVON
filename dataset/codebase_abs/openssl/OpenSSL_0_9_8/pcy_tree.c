static int F_1 ( T_1 * V_1 ,
const T_2 * V_2 )
{
int V_3 ;
T_1 * V_4 ;
T_3 * V_5 ;
T_4 * V_6 ;
V_4 = V_1 - 1 ;
for ( V_3 = 0 ; V_3 < F_2 ( V_2 -> V_5 ) ; V_3 ++ )
{
V_5 = F_3 ( V_2 -> V_5 , V_3 ) ;
if ( ( V_5 -> V_7 & V_8 )
&& ! ( V_1 -> V_7 & V_9 ) )
continue;
V_6 = F_4 ( V_4 , V_5 -> V_10 ) ;
if ( ! V_6 )
V_6 = V_4 -> V_11 ;
if ( V_6 && ! F_5 ( V_1 , V_5 , V_6 , NULL ) )
return 0 ;
}
return 1 ;
}
static int F_6 ( T_1 * V_1 ,
const T_2 * V_2 ,
T_5 * V_12 )
{
int V_3 ;
T_3 * V_5 ;
T_4 * V_13 ;
T_1 * V_4 ;
V_4 = V_1 - 1 ;
for ( V_3 = 0 ; V_3 < F_7 ( V_4 -> V_14 ) ; V_3 ++ )
{
V_13 = F_8 ( V_4 -> V_14 , V_3 ) ;
if ( V_13 -> V_15 )
continue;
V_5 = F_9 ( NULL , V_13 -> V_5 -> V_10 ,
F_10 ( V_13 ) ) ;
if ( V_5 == NULL )
return 0 ;
V_5 -> V_16 = V_1 -> V_11 -> V_5 -> V_16 ;
V_5 -> V_7 |= V_17 ;
if ( ! F_5 ( V_1 , V_5 , V_13 , V_12 ) )
{
F_11 ( V_5 ) ;
return 0 ;
}
}
if ( V_4 -> V_11 )
{
if ( ! F_5 ( V_1 , V_2 -> V_11 ,
V_4 -> V_11 , NULL ) )
return 0 ;
}
return 1 ;
}
static int F_12 ( T_5 * V_12 , T_1 * V_1 )
{
T_4 * V_13 ;
int V_3 ;
for ( V_3 = F_7 ( V_1 -> V_14 ) - 1 ; V_3 >= 0 ; V_3 -- )
{
V_13 = F_8 ( V_1 -> V_14 , V_3 ) ;
if ( V_13 -> V_5 -> V_7 & V_18 )
{
V_13 -> V_6 -> V_15 -- ;
F_13 ( V_13 ) ;
F_14 ( V_1 -> V_14 , V_3 ) ;
}
}
for(; ; ) {
-- V_1 ;
for ( V_3 = F_7 ( V_1 -> V_14 ) - 1 ; V_3 >= 0 ; V_3 -- )
{
V_13 = F_8 ( V_1 -> V_14 , V_3 ) ;
if ( V_13 -> V_15 == 0 )
{
V_13 -> V_6 -> V_15 -- ;
F_13 ( V_13 ) ;
F_14 ( V_1 -> V_14 , V_3 ) ;
}
}
if ( V_1 -> V_11 && ! V_1 -> V_11 -> V_15 )
{
if ( V_1 -> V_11 -> V_6 )
V_1 -> V_11 -> V_6 -> V_15 -- ;
F_13 ( V_1 -> V_11 ) ;
V_1 -> V_11 = NULL ;
}
if ( V_1 == V_12 -> V_19 )
{
if ( ! V_1 -> V_11 )
return 2 ;
return 1 ;
}
}
return 1 ;
}
static int F_15 ( T_5 * V_12 )
{
int V_20 , V_3 ;
T_1 * V_1 = V_12 -> V_19 + 1 ;
const T_2 * V_2 ;
for( V_3 = 1 ; V_3 < V_12 -> V_21 ; V_3 ++ , V_1 ++ )
{
V_2 = F_16 ( V_1 -> V_22 ) ;
if ( ! F_1 ( V_1 , V_2 ) )
return 0 ;
if ( ! ( V_1 -> V_7 & V_9 )
&& ! F_6 ( V_1 , V_2 , V_12 ) )
return 0 ;
V_20 = F_12 ( V_12 , V_1 ) ;
if ( V_20 != 1 )
return V_20 ;
}
return 1 ;
}
static void F_17 ( T_4 * V_13 )
{
if ( V_13 -> V_5 && ( V_13 -> V_5 -> V_7 & V_23 ) )
F_13 ( V_13 ) ;
}
void F_18 ( T_5 * V_12 )
{
T_1 * V_1 ;
int V_3 ;
if ( ! V_12 )
return;
F_19 ( V_12 -> V_24 ) ;
F_20 ( V_12 -> V_25 , F_17 ) ;
for( V_3 = 0 , V_1 = V_12 -> V_19 ; V_3 < V_12 -> V_21 ; V_3 ++ , V_1 ++ )
{
if ( V_1 -> V_22 )
F_21 ( V_1 -> V_22 ) ;
if ( V_1 -> V_14 )
F_20 ( V_1 -> V_14 ,
V_26 ) ;
if ( V_1 -> V_11 )
V_26 ( V_1 -> V_11 ) ;
}
if ( V_12 -> V_27 )
F_22 ( V_12 -> V_27 ,
F_11 ) ;
F_13 ( V_12 -> V_19 ) ;
F_13 ( V_12 ) ;
}
