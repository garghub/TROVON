static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
V_4 -> V_5 = V_2 -> V_6 ;
return 0 ;
}
static T_1 F_2 ( struct V_3 * V_4 , char T_2 * V_7 , T_3 V_8 ,
T_4 * V_9 )
{
struct V_10 * V_11 = V_4 -> V_5 ;
struct V_12 * V_13 = V_11 -> V_13 ;
unsigned long V_14 ;
T_1 V_15 ;
char V_16 [ 16 ] ;
T_5 V_17 ;
if ( V_8 == 0 )
return - V_18 ;
if ( * V_9 > 0xffffff )
return 0 ;
if ( V_8 > 16 )
V_8 = 16 ;
V_15 = F_3 ( V_13 ) ;
if ( V_15 )
return V_15 ;
F_4 ( & V_13 -> V_19 . V_20 , V_14 ) ;
V_13 -> V_19 . V_21 = V_8 ;
V_13 -> V_19 . V_22 = V_16 ;
F_5 ( V_13 , V_23 , * V_9 & 0xffff ) ;
F_6 ( V_13 , * V_9 , V_8 ) ;
F_7 ( & V_13 -> V_19 . V_20 , V_14 ) ;
V_15 = F_8 ( V_13 ) ;
if ( ! V_15 )
V_17 = V_13 -> V_19 . V_21 ;
F_4 ( & V_13 -> V_19 . V_20 , V_14 ) ;
V_13 -> V_19 . V_22 = NULL ;
F_7 ( & V_13 -> V_19 . V_20 , V_14 ) ;
F_9 ( V_13 ) ;
if ( V_15 )
return V_15 ;
else if ( V_17 == 0 )
return - V_24 ;
if ( F_10 ( V_7 , V_16 , V_17 ) )
return - V_25 ;
* V_9 += V_17 ;
V_15 = V_17 ;
return V_15 ;
}
static int F_11 ( struct V_26 * V_4 , void * V_27 )
{
struct V_10 * V_11 = V_4 -> V_28 ;
const char * V_29 = NULL ;
unsigned long V_14 ;
T_6 V_30 ;
F_4 ( & V_11 -> V_13 -> V_19 . V_20 , V_14 ) ;
V_30 = V_11 -> V_13 -> V_19 . V_30 ;
F_7 ( & V_11 -> V_13 -> V_19 . V_20 , V_14 ) ;
if ( V_30 < V_31 )
V_29 = V_32 [ V_30 ] ;
if ( ! V_29 )
V_29 = L_1 ;
F_12 ( V_4 , L_2 , V_29 ) ;
return 0 ;
}
static int F_13 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
return F_14 ( V_4 , F_11 , V_2 -> V_6 ) ;
}
static T_1 F_15 ( struct V_3 * V_4 , const char T_2 * V_7 ,
T_3 V_8 , T_4 * V_9 )
{
struct V_10 * V_11 = V_4 -> V_5 ;
unsigned long V_14 ;
char V_16 [ 16 ] ;
T_1 V_33 ;
int V_2 ;
if ( V_8 == 0 )
return - V_18 ;
V_33 = F_16 ( ( T_3 ) 15 , V_8 ) ;
if ( F_17 ( V_16 , V_7 , V_33 ) )
return - V_25 ;
V_16 [ 15 ] = 0 ;
for ( V_2 = 0 ; V_2 < V_31 ; ++ V_2 ) {
if ( ! V_32 [ V_2 ] )
continue;
if ( ! strcasecmp ( V_16 , V_32 [ V_2 ] ) )
break;
}
if ( V_2 == V_31 )
V_2 = F_18 ( V_16 , NULL , 10 ) ;
F_4 ( & V_11 -> V_13 -> V_19 . V_20 , V_14 ) ;
F_19 ( V_11 -> V_13 , ( T_6 ) V_2 ) ;
F_7 ( & V_11 -> V_13 -> V_19 . V_20 , V_14 ) ;
return V_33 ;
}
int F_20 ( struct V_12 * V_13 )
{
struct V_10 * V_11 ;
unsigned long V_14 ;
int V_15 = - V_34 ;
V_11 = F_21 ( sizeof( * V_11 ) , V_35 ) ;
if ( ! V_11 )
return - V_34 ;
V_11 -> V_13 = V_13 ;
V_11 -> V_36 = F_22 ( L_3 , V_37 ,
V_11 -> V_13 -> V_38 -> V_39 , V_11 , & V_40 ) ;
if ( ! V_11 -> V_36 )
goto V_41;
V_11 -> V_30 = F_22 ( L_4 , V_37 ,
V_11 -> V_13 -> V_38 -> V_39 , V_11 , & V_42 ) ;
if ( ! V_11 -> V_30 )
goto V_43;
F_4 ( & V_13 -> V_19 . V_20 , V_14 ) ;
V_13 -> V_44 = V_11 ;
F_7 ( & V_13 -> V_19 . V_20 , V_14 ) ;
return 0 ;
V_43:
F_23 ( V_11 -> V_36 ) ;
V_41:
F_24 ( V_11 ) ;
return V_15 ;
}
void F_25 ( struct V_12 * V_13 )
{
struct V_10 * V_11 = V_13 -> V_44 ;
unsigned long V_14 ;
if ( ! V_11 )
return;
F_4 ( & V_13 -> V_19 . V_20 , V_14 ) ;
V_13 -> V_44 = NULL ;
F_7 ( & V_13 -> V_19 . V_20 , V_14 ) ;
F_23 ( V_11 -> V_30 ) ;
F_23 ( V_11 -> V_36 ) ;
F_24 ( V_11 ) ;
}
