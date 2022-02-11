static int F_1 ( void * V_1 , unsigned int V_2 , unsigned int * V_3 )
{
struct V_4 * V_5 = V_1 ;
struct V_6 * V_7 = F_2 ( V_5 , struct V_6 , V_5 ) ;
int V_8 = 0 ;
if ( V_2 > 255 )
return - V_9 ;
F_3 ( & V_7 -> V_10 -> V_11 ) ;
if ( ! F_4 ( V_7 ) ) {
F_5 ( V_7 -> V_10 , V_12 ) ;
F_5 ( V_7 -> V_10 , V_2 ) ;
* V_3 = F_6 ( V_7 -> V_10 ) ;
} else {
V_8 = - V_13 ;
}
F_7 ( & V_7 -> V_10 -> V_11 ) ;
return V_8 ;
}
static int F_8 ( void * V_1 , unsigned int V_2 , unsigned int V_3 )
{
struct V_4 * V_5 = V_1 ;
struct V_6 * V_7 = F_2 ( V_5 , struct V_6 , V_5 ) ;
int V_8 = 0 ;
if ( V_2 > 255 )
return - V_9 ;
F_3 ( & V_7 -> V_10 -> V_11 ) ;
if ( ! F_4 ( V_7 ) ) {
F_5 ( V_7 -> V_10 , V_14 ) ;
F_5 ( V_7 -> V_10 , V_2 ) ;
F_5 ( V_7 -> V_10 , V_3 ) ;
} else {
V_8 = - V_13 ;
}
F_7 ( & V_7 -> V_10 -> V_11 ) ;
return V_8 ;
}
static int F_9 ( void * V_1 , unsigned int V_2 ,
unsigned int * V_3 )
{
struct V_4 * V_5 = V_1 ;
struct V_6 * V_7 = F_2 ( V_5 , struct V_6 , V_5 ) ;
int V_8 = 0 ;
if ( V_2 > 255 )
return - V_9 ;
F_3 ( & V_7 -> V_10 -> V_11 ) ;
if ( ! F_4 ( V_7 ) ) {
F_5 ( V_7 -> V_10 , V_12 ) ;
F_5 ( V_7 -> V_10 , V_2 ) ;
* V_3 = F_6 ( V_7 -> V_10 ) ;
* V_3 |= F_6 ( V_7 -> V_10 ) << 8 ;
} else {
V_8 = - V_13 ;
}
F_7 ( & V_7 -> V_10 -> V_11 ) ;
return V_8 ;
}
static int F_10 ( void * V_1 , unsigned int V_2 ,
unsigned int V_3 )
{
struct V_4 * V_5 = V_1 ;
struct V_6 * V_7 = F_2 ( V_5 , struct V_6 , V_5 ) ;
int V_8 = 0 ;
if ( V_2 > 255 )
return - V_9 ;
F_3 ( & V_7 -> V_10 -> V_11 ) ;
if ( ! F_4 ( V_7 ) ) {
F_5 ( V_7 -> V_10 , V_14 ) ;
F_5 ( V_7 -> V_10 , V_2 ) ;
F_5 ( V_7 -> V_10 , V_3 & 0x00FF ) ;
F_5 ( V_7 -> V_10 , V_3 >> 8 & 0x00FF ) ;
} else {
V_8 = - V_13 ;
}
F_7 ( & V_7 -> V_10 -> V_11 ) ;
return V_8 ;
}
static int F_11 ( void * V_1 , unsigned int V_2 ,
unsigned int * V_3 )
{
struct V_4 * V_5 = V_1 ;
struct V_6 * V_7 = F_2 ( V_5 , struct V_6 , V_5 ) ;
int V_8 = 0 ;
if ( V_2 > 65535 )
return - V_9 ;
F_3 ( & V_7 -> V_10 -> V_11 ) ;
if ( ! F_4 ( V_7 ) ) {
F_5 ( V_7 -> V_10 , V_12 ) ;
F_5 ( V_7 -> V_10 , V_2 & 0x00FF ) ;
F_5 ( V_7 -> V_10 , V_2 >> 8 & 0x00FF ) ;
* V_3 = F_6 ( V_7 -> V_10 ) ;
* V_3 |= F_6 ( V_7 -> V_10 ) << 8 ;
} else {
V_8 = - V_13 ;
}
F_7 ( & V_7 -> V_10 -> V_11 ) ;
return V_8 ;
}
static int F_12 ( void * V_1 , unsigned int V_2 ,
unsigned int V_3 )
{
struct V_4 * V_5 = V_1 ;
struct V_6 * V_7 = F_2 ( V_5 , struct V_6 , V_5 ) ;
int V_8 = 0 ;
if ( V_2 > 65535 )
return - V_9 ;
F_3 ( & V_7 -> V_10 -> V_11 ) ;
if ( ! F_4 ( V_7 ) ) {
F_5 ( V_7 -> V_10 , V_14 ) ;
F_5 ( V_7 -> V_10 , V_2 & 0x00FF ) ;
F_5 ( V_7 -> V_10 , V_2 >> 8 & 0x00FF ) ;
F_5 ( V_7 -> V_10 , V_3 & 0x00FF ) ;
F_5 ( V_7 -> V_10 , V_3 >> 8 & 0x00FF ) ;
} else {
V_8 = - V_13 ;
}
F_7 ( & V_7 -> V_10 -> V_11 ) ;
return V_8 ;
}
static const struct V_15 * F_13 ( struct V_4 * V_16 ,
const struct V_17 * V_18 )
{
if ( V_18 -> V_19 == 8 && V_18 -> V_20 == 8 )
return & V_21 ;
if ( V_18 -> V_19 == 8 && V_18 -> V_20 == 16 )
return & V_22 ;
if ( V_18 -> V_19 == 16 && V_18 -> V_20 == 16 )
return & V_23 ;
return F_14 ( - V_24 ) ;
}
struct V_25 * F_15 ( struct V_4 * V_16 ,
const struct V_17 * V_18 ,
struct V_26 * V_27 ,
const char * V_28 )
{
const struct V_15 * V_29 = F_13 ( V_16 , V_18 ) ;
if ( F_16 ( V_29 ) )
return F_17 ( V_29 ) ;
return F_18 ( V_16 , V_29 , V_16 , V_18 ,
V_27 , V_28 ) ;
return NULL ;
}
struct V_25 * F_19 ( struct V_4 * V_16 ,
const struct V_17 * V_18 ,
struct V_26 * V_27 ,
const char * V_28 )
{
const struct V_15 * V_29 = F_13 ( V_16 , V_18 ) ;
if ( F_16 ( V_29 ) )
return F_17 ( V_29 ) ;
return F_20 ( V_16 , V_29 , V_16 , V_18 ,
V_27 , V_28 ) ;
return NULL ;
}
