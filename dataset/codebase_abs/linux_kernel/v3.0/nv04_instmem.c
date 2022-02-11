static int
F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( V_4 -> V_6 >= 0x40 )
return 128 ;
else
if ( V_4 -> V_6 >= 0x17 )
return 64 ;
return 32 ;
}
int F_2 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_7 * V_8 = NULL ;
T_1 V_9 , V_10 ;
int V_11 ;
V_4 -> V_12 = true ;
V_11 = F_3 ( V_2 , 0x10000 , ~ 0 , 4096 ,
V_13 , & V_8 ) ;
if ( V_11 )
return V_11 ;
V_11 = F_4 ( V_2 , V_8 , & V_4 -> V_8 ) ;
F_5 ( NULL , & V_8 ) ;
if ( V_11 )
return V_11 ;
V_11 = F_3 ( V_2 , 0x11200 , ~ 0 , 512 ,
V_13 , & V_4 -> V_14 ) ;
if ( V_11 )
return V_11 ;
V_10 = V_4 -> V_15 . V_16 . V_17 * F_1 ( V_2 ) ;
switch ( V_4 -> V_18 ) {
case V_19 :
V_9 = 0x20000 ;
break;
default:
V_9 = 0x11400 ;
break;
}
V_11 = F_3 ( V_2 , V_9 , ~ 0 , V_10 ,
V_13 , & V_4 -> V_20 ) ;
if ( V_11 )
return V_11 ;
V_9 += V_10 ;
if ( V_4 -> V_18 >= V_19 ) {
if ( V_9 < 0x40000 )
V_9 = 0x40000 ;
}
V_11 = F_6 ( & V_4 -> V_21 , V_9 ,
V_4 -> V_22 - V_9 ) ;
if ( V_11 ) {
F_7 ( V_2 , L_1 , V_11 ) ;
return V_11 ;
}
return 0 ;
}
void
F_8 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_9 ( NULL , & V_4 -> V_8 , NULL ) ;
F_5 ( NULL , & V_4 -> V_14 ) ;
F_5 ( NULL , & V_4 -> V_20 ) ;
if ( F_10 ( & V_4 -> V_21 ) )
F_11 ( & V_4 -> V_21 ) ;
}
int
F_12 ( struct V_1 * V_2 )
{
return 0 ;
}
void
F_13 ( struct V_1 * V_2 )
{
}
int
F_14 ( struct V_7 * V_23 , T_1 V_24 , T_1 V_25 )
{
struct V_3 * V_4 = V_23 -> V_2 -> V_5 ;
struct V_26 * V_27 = NULL ;
do {
if ( F_15 ( & V_4 -> V_21 ) )
return - V_28 ;
F_16 ( & V_4 -> V_29 ) ;
V_27 = F_17 ( & V_4 -> V_21 , V_24 , V_25 , 0 ) ;
if ( V_27 == NULL ) {
F_18 ( & V_4 -> V_29 ) ;
return - V_28 ;
}
V_27 = F_19 ( V_27 , V_24 , V_25 ) ;
F_18 ( & V_4 -> V_29 ) ;
} while ( V_27 == NULL );
V_23 -> V_30 = V_27 ;
V_23 -> V_31 = V_27 -> V_32 ;
return 0 ;
}
void
F_20 ( struct V_7 * V_23 )
{
struct V_3 * V_4 = V_23 -> V_2 -> V_5 ;
F_16 ( & V_4 -> V_29 ) ;
F_21 ( V_23 -> V_30 ) ;
V_23 -> V_30 = NULL ;
F_18 ( & V_4 -> V_29 ) ;
}
int
F_22 ( struct V_7 * V_23 )
{
V_23 -> V_33 = V_23 -> V_31 ;
return 0 ;
}
void
F_23 ( struct V_7 * V_23 )
{
}
void
F_24 ( struct V_1 * V_2 )
{
}
