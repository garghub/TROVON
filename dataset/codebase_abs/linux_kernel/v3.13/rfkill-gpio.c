static int F_1 ( void * V_1 , bool V_2 )
{
struct V_3 * V_4 = V_1 ;
if ( V_2 ) {
if ( F_2 ( V_4 -> V_5 ) )
F_3 ( V_4 -> V_5 , 0 ) ;
if ( F_2 ( V_4 -> V_6 ) )
F_3 ( V_4 -> V_6 , 0 ) ;
if ( ! F_4 ( V_4 -> V_7 ) && V_4 -> V_8 )
F_5 ( V_4 -> V_7 ) ;
} else {
if ( ! F_4 ( V_4 -> V_7 ) && ! V_4 -> V_8 )
F_6 ( V_4 -> V_7 ) ;
if ( F_2 ( V_4 -> V_6 ) )
F_3 ( V_4 -> V_6 , 1 ) ;
if ( F_2 ( V_4 -> V_5 ) )
F_3 ( V_4 -> V_5 , 1 ) ;
}
V_4 -> V_8 = V_2 ;
return 0 ;
}
static int F_7 ( struct V_9 * V_10 ,
struct V_3 * V_4 )
{
const struct V_11 * V_12 ;
V_12 = F_8 ( V_10 -> V_13 -> V_14 , V_10 ) ;
if ( ! V_12 )
return - V_15 ;
V_4 -> V_16 = F_9 ( V_10 ) ;
V_4 -> type = ( unsigned ) V_12 -> V_17 ;
V_4 -> V_6 = F_10 ( V_10 , 0 , NULL ) ;
V_4 -> V_5 = F_10 ( V_10 , 1 , NULL ) ;
return 0 ;
}
static int F_11 ( struct V_18 * V_19 )
{
struct V_20 * V_21 = V_19 -> V_10 . V_22 ;
struct V_3 * V_4 ;
const char * V_23 = NULL ;
int V_24 = 0 ;
int V_25 = 0 ;
V_4 = F_12 ( & V_19 -> V_10 , sizeof( * V_4 ) , V_26 ) ;
if ( ! V_4 )
return - V_27 ;
if ( F_13 ( & V_19 -> V_10 ) ) {
V_24 = F_7 ( & V_19 -> V_10 , V_4 ) ;
if ( V_24 )
return V_24 ;
} else if ( V_21 ) {
V_23 = V_21 -> V_28 ;
V_4 -> V_16 = V_21 -> V_16 ;
V_4 -> type = V_21 -> type ;
V_4 -> V_6 = V_21 -> V_6 ;
V_4 -> V_5 = V_21 -> V_5 ;
} else {
return - V_15 ;
}
if ( ( ! F_2 ( V_4 -> V_6 ) &&
! F_2 ( V_4 -> V_5 ) ) || ! V_4 -> V_16 ) {
F_14 ( L_1 , V_29 ) ;
return - V_30 ;
}
if ( V_21 && V_21 -> V_31 ) {
V_24 = V_21 -> V_31 ( V_19 ) ;
if ( V_24 ) {
F_14 ( L_2 , V_29 ) ;
return V_24 ;
}
}
V_25 = strlen ( V_4 -> V_16 ) ;
V_4 -> V_32 = F_12 ( & V_19 -> V_10 , V_25 + 7 , V_26 ) ;
if ( ! V_4 -> V_32 )
return - V_27 ;
V_4 -> V_33 = F_12 ( & V_19 -> V_10 , V_25 + 10 , V_26 ) ;
if ( ! V_4 -> V_33 )
return - V_27 ;
snprintf ( V_4 -> V_32 , V_25 + 6 , L_3 , V_4 -> V_16 ) ;
snprintf ( V_4 -> V_33 , V_25 + 9 , L_4 , V_4 -> V_16 ) ;
V_4 -> V_7 = F_15 ( & V_19 -> V_10 , V_23 ) ;
if ( F_2 ( V_4 -> V_6 ) ) {
V_24 = F_16 ( & V_19 -> V_10 , V_4 -> V_6 ,
0 , V_4 -> V_32 ) ;
if ( V_24 ) {
F_14 ( L_5 , V_29 ) ;
return V_24 ;
}
}
if ( F_2 ( V_4 -> V_5 ) ) {
V_24 = F_16 ( & V_19 -> V_10 , V_4 -> V_5 ,
0 , V_4 -> V_33 ) ;
if ( V_24 ) {
F_14 ( L_6 , V_29 ) ;
return V_24 ;
}
}
V_4 -> V_34 = F_17 ( V_4 -> V_16 , & V_19 -> V_10 ,
V_4 -> type , & V_35 ,
V_4 ) ;
if ( ! V_4 -> V_34 )
return - V_27 ;
V_24 = F_18 ( V_4 -> V_34 ) ;
if ( V_24 < 0 )
return V_24 ;
F_19 ( V_19 , V_4 ) ;
F_20 ( & V_19 -> V_10 , L_7 , V_4 -> V_16 ) ;
return 0 ;
}
static int F_21 ( struct V_18 * V_19 )
{
struct V_3 * V_4 = F_22 ( V_19 ) ;
struct V_20 * V_21 = V_19 -> V_10 . V_22 ;
if ( V_21 && V_21 -> V_36 )
V_21 -> V_36 ( V_19 ) ;
F_23 ( V_4 -> V_34 ) ;
F_24 ( V_4 -> V_34 ) ;
return 0 ;
}
